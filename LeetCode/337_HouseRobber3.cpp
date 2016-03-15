// https://leetcode.com/problems/house-robber-iii/

#include <iostream>
#include <map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void freeNodes(TreeNode* node) {
	if (node == NULL) return;

	freeNodes(node->left);
	delete node->left;
	node->left = NULL;

	freeNodes(node->right);
	delete node->right;
	node->right = NULL;
}

class Solution {
private:
	map<TreeNode*, int> cacheO, cacheX;
	map<TreeNode*, int>::iterator it;

	int maxSumO(TreeNode* node) {
		int sum;

		if (node == NULL) return 0;

		it = cacheO.find(node);
		if (it != cacheO.end()) return it->second;

		sum = maxSumX(node->left) + maxSumX(node->right) + node->val;

		cacheO.insert(make_pair(node, sum));

		return sum;
	}
	int maxSumX(TreeNode* node) {
		int sum;

		if (node == NULL) return 0;

		it = cacheX.find(node);
		if (it != cacheX.end()) return it->second;

		sum = max(maxSumO(node->left), maxSumX(node->left)) + max(maxSumO(node->right), maxSumX(node->right));

		cacheX.insert(make_pair(node, sum));

		return sum;
	}
public:
    int rob(TreeNode* root) {
        return max(maxSumO(root), maxSumX(root));
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	TreeNode* root;

	root = new TreeNode(3);
	root->left = new TreeNode(4);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->right = new TreeNode(1);

	cout << s.rob(root) << "\n";

	freeNodes(root);
	delete root;
	root = NULL;

	return 0;
}

/*
3, 4, 5, 1, 3, null, 1
=====
9
*/
