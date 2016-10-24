//
//  main.cpp
//  LeetCode_437_PathSum3
//
//  Created by Youngduke Koh on 10/24/16.
//  Copyright © 2016 Youngduke Koh. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int ans;
    map<int, int> treverse(TreeNode* node, int sum) {
        map<int, int> m, temp;
        map<int, int>::iterator it;
        
        if (node == NULL) return m;
        
        m[node->val]++;
        
        temp = treverse(node->left, sum);
        for (it = temp.begin(); it != temp.end(); it++) {
            m[it->first + node->val] += it->second;
        }
        
        temp = treverse(node->right, sum);
        for (it = temp.begin(); it != temp.end(); it++) {
            m[it->first + node->val] += it->second;
        }
        
        ans += m[sum];
        
        return m;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        ans = 0;
        treverse(root, sum);
        
        return ans;
    }
};

void freeTreeNode(TreeNode* node) {
    if (node == NULL) return;

    if (node->left) {
        freeTreeNode(node->left);
        delete node->left;
    }
    
    if (node->right) {
        freeTreeNode(node->right);
        delete node->right;
    }
}

int main(int argc, const char * argv[]) {
    Solution s;
    TreeNode* node = NULL;
    
    node = new TreeNode(10);
    node->left = new TreeNode(5);
    node->right = new TreeNode(-3);
    node->left->left = new TreeNode(3);
    node->left->right = new TreeNode(2);
    node->right->right = new TreeNode(11);
    node->left->left->left = new TreeNode(3);
    node->left->left->right = new TreeNode(-2);
    node->left->right->right = new TreeNode(1);
    
    cout << s.pathSum(node, 8) << "\n";
    cout << s.pathSum(node, 1) << "\n";
    cout << s.pathSum(node, 100) << "\n";
    
    freeTreeNode(node);
    node = NULL;
    
    return 0;
}
