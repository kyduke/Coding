// https://careercup.com/question?id=5749533368647680

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int v) : left(NULL), right(NULL) {val = v;} 
};

void freeNodes(Node* node) {
	if (node == NULL) return;

	freeNodes(node->left);
	delete node->left;
	freeNodes(node->right);
	delete node->right;
}

void printTreeColumnOrder(Node* root) {
	map<int, vector<int>> m;
	map<int, vector<int>>::iterator it;
	vector<int> arr;
	queue<pair<Node*, int>> q;
	Node* node;
	int i;

	q.push(make_pair(root, 0));
	while (!q.empty()) {
		node = q.front().first;
		i = q.front().second;
		q.pop();

		if (node == NULL) continue;

		it = m.find(i);
		if (it == m.end()) {
			arr.clear();
			arr.push_back(node->val);
			m.insert(make_pair(i, arr));
		} else {
			it->second.push_back(node->val);
		}

		q.push(make_pair(node->left, i - 1));
		q.push(make_pair(node->right, i + 1));
	}

	for (it = m.begin(); it != m.end(); it++) {
		for (i = 0; i < it->second.size(); i++) {
			cout << it->second[i] << " ";
		}
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	Node* root;

	root = new Node(6);
	root->left = new Node(3);
	root->right = new Node(4);
	root->left->left = new Node(5);
	root->left->right = new Node(1);
	root->right->right = new Node(0);
	root->left->left->left = new Node(9);
	root->left->left->right = new Node(2);
	root->right->right->left = new Node(8);
	root->left->left->right->right = new Node(7);

	printTreeColumnOrder(root);

	freeNodes(root);
	delete root;

	return 0;
}
