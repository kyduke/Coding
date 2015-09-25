// https://leetcode.com/problems/binary-tree-paths/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	vector<int> path;
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
	string path2string() {
		string str;
		int i;

		str = "";
		for (i = 0; i < path.size() - 1; i++) {
			str += integerToString(path[i]) + "->";
		}
		str += integerToString(path[i]);

		return str;
		
	}
	void makeTreePath(TreeNode* node) {
		if (node == NULL) return;

		path.push_back(node->val);

		if (node->left == NULL && node->right == NULL) {
			result.push_back(path2string());
		} else {
			makeTreePath(node->left);
			makeTreePath(node->right);
		}

		path.pop_back();
	}
public:
	vector<string> result;
    vector<string> binaryTreePaths(TreeNode* root) {
		result.clear();
		path.clear();

		makeTreePath(root);

		return result;
    }
};

void freeChild(TreeNode* node) {
	if (node == NULL) return;

	if (node->left) {
		freeChild(node->left);
		delete node->left;
		node->left = NULL;
	}
	if (node->right) {
		freeChild(node->right);
		delete node->right;
		node->right = NULL;
	}
}

int main(int argc, char* argv[]) {
	Solution s;
	TreeNode *root;
	vector<string> result;
	int i;

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(5);

	result = s.binaryTreePaths(root);

	freeChild(root);
	delete root;

	for (i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

	return 0;
}
