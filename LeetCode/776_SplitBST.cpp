// https://leetcode.com/contest/weekly-contest-70/problems/split-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	TreeNode* targetParent;
	TreeNode* parent;
	int leftOrRight;
	TreeNode* findTarget(TreeNode* node, int v) {
		TreeNode* target = NULL;

		if (node == NULL) return node;
		if (node->val == v) {
			return node;
		}
		
		if (node->val >= v) {
			target = findTarget(node->left, v);
			if (target != NULL) {
				if (targetParent == NULL && target != NULL) {
					leftOrRight = 1;
					targetParent = node;
				}
				return target;
			}
		}
		
		if (node->val == v) {
			target = findTarget(node->right, v);
		}
		if (targetParent == NULL && target != NULL) {
			leftOrRight = 2;
			targetParent = node;
		}
		
		return target;
	}
	TreeNode* findBigRight(TreeNode* node, int v) {
		TreeNode* target = NULL;

		if (node == NULL) return node;
		if (node->val > v) {
			return node;
		}
		
		target = findBigRight(node->right, v);
		if (parent == NULL && target != NULL) {
			parent = node;
		}
		return target;
	}
public:
    vector<TreeNode*> splitBST(TreeNode* root, int v) {
		vector<TreeNode*> ans;
        TreeNode* target = NULL;
		TreeNode* targetRight = NULL;

		leftOrRight = -1;

		targetParent = NULL;
		target = findTarget(root, v);
		
		parent = NULL;
		targetRight = findBigRight(target, v);
		if (parent != NULL) {
			parent->right = NULL;
		}

		if (targetParent != NULL) {
			if (leftOrRight == 1) {
				targetParent->left = targetRight;
			} else {
				targetParent->right = targetRight;
			}
		}

		if (target == root) {
			root = targetRight;
		}
		
		ans.push_back(root);
		ans.push_back(target);

		return ans;
    }
};
