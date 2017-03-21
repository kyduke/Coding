// https://leetcode.com/problems/diameter-of-binary-tree/#/description

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
    int getLength(TreeNode* node) {
        int lenLeft, lenRight;
        
        if (node == NULL) return 0;
        
        lenLeft = getLength(node->left);
        lenRight = getLength(node->right);
        
        ans = max(ans, lenLeft + lenRight);
        
        return max(lenLeft, lenRight) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        
        getLength(root);
        
        return ans;
    }
};
