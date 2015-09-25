// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int left, right;
        TreeNode* node;
        
        if (root == NULL || p == NULL || q == NULL) return NULL;
        
        left = min(p->val, q->val);
        right = max(p->val, q->val);
        
        node = root;
        while (node != NULL) {
            if (node->val < left) {
                node = node->right;
            } else if (node->val > right) {
                node = node->left;
            } else {
                break;
            }
        }
        
        return node;
    }
};
