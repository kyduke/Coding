// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
	string integerToString(int n) {
		string str;
		string table[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
		int sign;
		
		if (n == 0) return "0";
	
		sign = 1;
		if (n < 0) {
			sign = -1;
			n = -n;
		}
	
		str = "";
		while (n) {
			str = table[n % 10] + str;
			n /= 10;
		}
	
		if (sign == -1) {
			str = "-" + str;
		}
	
		return str;
	}
	int stringToInteger(string str) {
		int sign, i, n;
		
		n = 0;
		if (str.size() == 0) return n;

		i = 0;
		sign = 1;
		if (str[i] == '-') {
			i = 1;
			sign = -1;
		}
	
		while (i < str.size()) {
			n = n * 10 + (str[i] - '0');
			i++;
		}
	
		n = n * sign;
	
		return n;
	}
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;
		TreeNode* node;
		int n;
		string str;

		str = "";
		s.push(make_pair(root, 0));
		while (!s.empty()) {
			node = s.top().first;
			n = s.top().second;
			if (node == NULL) {
				s.pop();
				continue;
			}
			if (n == 0) {
				if (node->left) {
					str += "[";
				} else {
					str += "(";
				}
				str += integerToString(node->val);
				if (node->right) {
					str += "]";
				} else {
					str += ")";
				}
				s.top().second = 1;
				s.push(make_pair(node->left, 0));
			} else if (n == 1) {
				s.top().second = 2;
				s.push(make_pair(node->right, 0));
			} else {
				s.pop();
			}
		}

		return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		stack<pair<TreeNode*, int>> s;
		TreeNode* root = NULL;
		TreeNode* node = NULL;
		string left, num, right;
		int i, n;

		left = "";
		num = "";
		right = "";

		i = 0;
		while (i < data.size()) {
			if (data[i] == '(' || data[i] == '[') {
				left += data[i];
			} else if (data[i] == ')' || data[i] == ']') {
				right += data[i];

				if (root == NULL) {
					root = new TreeNode(stringToInteger(num));
					node = root;
				} else {
					node = s.top().first;
					n = s.top().second;
					if (n == 0) {
						s.top().second = 1;
						node->left = new TreeNode(stringToInteger(num));
						node = node->left;
					} else if (n == 1) {
						s.pop();
						node->right = new TreeNode(stringToInteger(num));
						node = node->right;
					} else if (n == 2) {
						s.pop();
						node->left = new TreeNode(stringToInteger(num));
						node = node->left;
					}
				}

				if (left[0] == '[' && right[0] == ']') {
					s.push(make_pair(node, 0));
				} else if (left[0] == '(' && right[0] == ']') {
					s.push(make_pair(node, 1));
				} else if (left[0] == '[' && right[0] == ')') {
					s.push(make_pair(node, 2));
				}

				left = "";
				num = "";
				right = "";
			} else {
				num += data[i];
			}
			i++;
		}

        return root;
    }
};

void printBTree(TreeNode* node) {
	stack<pair<TreeNode*, int>> s;
	int n;

	s.push(make_pair(node, 0));
	while (!s.empty()) {
		node = s.top().first;
		n = s.top().second;
		if (node == NULL) {
			s.pop();
			continue;
		}
		if (n == 0) {
			cout << node->val << " ";
			s.top().second = 1;
			s.push(make_pair(node->left, 0));
		} else {
			s.pop();
			s.push(make_pair(node->right, 0));
		}
	}
	cout << "\n";
}

void deleteBTree(TreeNode* node) {
	stack<pair<TreeNode*, int>> s;
	int n;

	s.push(make_pair(node, 0));
	while (!s.empty()) {
		node = s.top().first;
		n = s.top().second;
		if (node == NULL) {
			s.pop();
			continue;
		}
		if (n == 0) {
			s.top().second = 1;
			s.push(make_pair(node->left, 0));
		} else if (n == 1) {
			s.top().second = 2;
			s.push(make_pair(node->right, 0));
		} else {
			s.pop();
			if (node->left) delete node->left;
			if (node->right) delete node->right;
			node->left = NULL;
			node->right = NULL;
		}
	}
}

int main(int argc, char* argv[]) {
	Codec codec;
	TreeNode* root;
	string str;

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(7);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);

	printBTree(root);

	str = codec.serialize(root);
	cout << str << "\n";

	deleteBTree(root);
	if (root != NULL) delete root;
	root = NULL;

	root = codec.deserialize(str);

	printBTree(root);

	str = codec.serialize(root);
	cout << str << "\n";

	deleteBTree(root);
	if (root != NULL) delete root;
	root = NULL;

	return 0;
}
