// https://www.hackerrank.com/challenges/find-strings
// 3, 4, 5, 6 timeout

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
	char val;
	int depth;
	int childrenCount;
	vector<Node*> children;
	Node(char c,int d, int n) : val(c), depth(d), childrenCount(n) {}
};

struct Compare {
	bool operator() (const Node* a, const Node* b) const {
		return a->val < b->val;
	}
};

bool exist(Node* root, string s) {
	queue<Node*> q;
	Node* node;
	int i, j;
	char c;

	i = 0;
	c = s[i];
	q.push(root);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (node->val == 0) {
			for (j = 0; j < node->children.size(); j++) {
				q.push(node->children[j]);
			}
			continue;
		}
		if (node->depth > i) return false;
		if (node->depth < i) continue;

		if (node->val == c) {
			if (i == s.size() - 1) {
				return true;
			} else {
				i++;
				c = s[i];
				for (j = 0; j < node->children.size(); j++) {
					q.push(node->children[j]);
				}
			}
		}
	}

	return false;
}

void addNode(Node* root, string s) {
	queue<Node*> q;
	Node* node;
	int i, j;
	char c;

	i = 0;
	c = s[i];
	q.push(root);
	while (!q.empty()) {
		node = q.front();
		q.pop();

		if (node->val == 0) {
			node->childrenCount++;
			if (s.size() == 1) {
				node->children.push_back(new Node(c, 0, 1));
				sort(node->children.begin(), node->children.end(), Compare());
				return;
			}
			for (j = 0; j < node->children.size(); j++) {
				q.push(node->children[j]);
			}
			continue;
		}

		if (node->depth < i) continue;

		if (node->val == c) {
			node->childrenCount++;
			if (i == s.size() - 2) {
				node->children.push_back(new Node(s[i + 1], i + 1, 1));
				sort(node->children.begin(), node->children.end(), Compare());
				return;
			} else {
				i++;
				c = s[i];
				for (j = 0; j < node->children.size(); j++) {
					q.push(node->children[j]);
				}
			}
		}
	}
}

string getStringByIndex(Node* root, int n) {
	queue<Node*> q;
	Node* node;
	string str;
	int i;

	str = "";

	q.push(root);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (node->val == 0) {
			for (i = 0; i < node->children.size(); i++) {
				q.push(node->children[i]);
			}
			continue;
		}

		if (node->depth < str.size()) continue;

		if (node->childrenCount < n) {
			n -= node->childrenCount;
		} else {
			str += node->val;
			n--;
			if (n == 0) break;
			for (i = 0; i < node->children.size(); i++) {
				q.push(node->children[i]);
			}
		}
	}

	return str;
}

void findStrings(vector<string> a, vector<int> a_query) {
	Node* root = NULL;
	set<string> strs;
	set<string>::iterator it;
	string str, sub;
	int i, j, k, length;

	root = new Node(0, -1, 0);

	length = 0;
	for (i = 0; i < a.size(); i++) {
		if (length < a[i].size()) length = a[i].size();
	}

	for (i = 1; i <= length; i++) {
		strs.clear();
		for (j = 0; j < a.size(); j++) {
			str = a[j];
			if (str.size() < i) continue;
			for (k = 0; i + k <= str.size(); k++) {
				strs.insert(str.substr(k, i));
			}
		}
		for (it = strs.begin(); it != strs.end(); it++) {
			addNode(root, *it);
		}
	}

	for (i = 0; i < a_query.size(); i++) {
		if (a_query[i] > root->childrenCount) {
			cout << "INVALID\n";
		} else {
			cout << getStringByIndex(root, a_query[i]) << "\n";
		}
	}

	delete root;
	root = NULL;
}

int main(int argc, char* argv[]) {
	vector<string> a;
	vector<int> a_query;

	a.push_back("aab");
	a.push_back("aac");

	a_query.push_back(3);
	a_query.push_back(8);
	a_query.push_back(23);

	findStrings(a, a_query);

	return 0;
}

/*
2
aab
aac
3
3
8
23
=====
aab
c
INVALID
*/
