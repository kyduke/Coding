// https://leetcode.com/problems/longest-univalue-path/description/

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
    int ans;
    int traverse(TreeNode* node) {
        int a, b, temp;
        
        if (node == NULL) return 0;
        
        a = 0;
        if (node->left != NULL) {
            temp = traverse(node->left);
            if (node->left->val == node->val) a += temp;
        }
        
        b = 0;
        if (node->right != NULL) {
            temp = traverse(node->right);
            if (node->right->val == node->val) b += temp;
        }
        if (a + b > ans) ans = a + b;
        
        return max(a, b) + 1;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        
        traverse(root);
        
        return ans;
    }
};
