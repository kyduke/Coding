// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<TreeNode*> parents;
	TreeNode* answer;
    bool findNodeAndCheckParent(TreeNode* node, TreeNode* target) {
        bool found;
        
        if (node == NULL) return false;
        
        parents.push_back(node);
        
        if (node == target) return true;
        
        found = findNodeAndCheckParent(node->left, target) || findNodeAndCheckParent(node->right, target);
        
        if (found == true) return true;
        
        parents.pop_back();
        
        return false;
    }
    bool findNodeAndParent(TreeNode* node, TreeNode* target) {
        vector<TreeNode*>::iterator it;
		bool found;

		if (node == NULL) return false;

		found = (node == target) || findNodeAndParent(node->left, target) || findNodeAndParent(node->right, target);

		if (found == true && answer == NULL) {
			it = find(parents.begin(), parents.end(), node);
			if (it != parents.end()) {
				answer = *it;
			}
		}

		return found;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		answer = NULL;
        if (findNodeAndCheckParent(root, p) == true) {
            findNodeAndParent(root, q);
        }
        return answer;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	TreeNode* root;
	TreeNode* node = NULL;

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	node = s.lowestCommonAncestor(root, root->left, root->right);
	if (node == NULL) {
		cout << "NULL\n";
	} else {
		cout << node->val << "\n";
	}

	node = s.lowestCommonAncestor(root, root->left->left, root->left->right);
	if (node == NULL) {
		cout << "NULL\n";
	} else {
		cout << node->val << "\n";
	}

	return 0;
}
