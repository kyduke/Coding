// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int kthElement;
	int findKth(TreeNode* node, int k) {
		if (node == NULL || k == 0) return k;

		k = findKth(node->left, k);

		k--;
		if (k == 0) {
			kthElement = node->val;
		}

		k = findKth(node->right, k);

		return k;
	}
public:
	int kthSmallest(TreeNode* root, int k) {
		kthElement = 0;
		findKth(root, k);

		return kthElement;
	}
};

void insertTreeNode(TreeNode* node, int n) {
	if (node == NULL) return;

	if (n <= node->val) {
		if (node->left) {
			insertTreeNode(node->left, n);
		} else {
			node->left = new TreeNode(n);
		}
	} else {
		if (node->right) {
			insertTreeNode(node->right, n);
		} else {
			node->right = new TreeNode(n);
		}
	}
}

void deleteTreeNode(TreeNode* node) {
	if (node == NULL) return;

	if (node->left) {
		deleteTreeNode(node->left);
		delete node->left;
	}

	if (node->right) {
		deleteTreeNode(node->right);
		delete node->right;
	}
}

int main(int argc, char* argv[]) {
	Solution s;
	TreeNode* root;

	root = new TreeNode(700);
	insertTreeNode(root, 400);
	insertTreeNode(root, 200);
	insertTreeNode(root, 600);
	insertTreeNode(root, 100);
	insertTreeNode(root, 300);
	insertTreeNode(root, 500);
	insertTreeNode(root, 900);
	insertTreeNode(root, 800);
	insertTreeNode(root, 1100);
	insertTreeNode(root, 1000);
	insertTreeNode(root, 1200);

	cout << "1: " << s.kthSmallest(root, 1) << "\n";
	cout << "2: " << s.kthSmallest(root, 2) << "\n";
	cout << "5: " << s.kthSmallest(root, 5) << "\n";
	cout << "7: " << s.kthSmallest(root, 7) << "\n";
	cout << "8: " << s.kthSmallest(root, 8) << "\n";
	cout << "10: " << s.kthSmallest(root, 10) << "\n";
	cout << "11: " << s.kthSmallest(root, 11) << "\n";
	cout << "12: " << s.kthSmallest(root, 12) << "\n";

	deleteTreeNode(root);
	delete root;

	return 0;
}
