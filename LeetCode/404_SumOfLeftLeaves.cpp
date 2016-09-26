// https://leetcode.com/problems/sum-of-left-leaves/

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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode*, bool>> q;
        TreeNode* node;
        bool left;
        int sum;
        
        sum = 0;
        
        q.push(make_pair(root, false));
        
        while(!q.empty()) {
            node = q.front().first;
            left = q.front().second;
            q.pop();
            if (node == NULL) {
                continue;
            }
            if (left && node->left == NULL && node->right == NULL) {
                sum += node->val;
            }
            q.push(make_pair(node->left, true));
            q.push(make_pair(node->right, false));
        }
        
        return sum;
    }
};
