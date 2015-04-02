//Convert Sorted List to Balanced Binary Search Tree
class Solution {
private:
    int depth;
    int leafs;
    void calcDepthAndLeafs(ListNode *head) {
        int n = 0, c = 1;
        while (head) {
            head = head->next;
            n++;
        }
        while (n > 0) {
            leafs = n;
            n = n - c;
            c = c * 2;
            depth++;
        }
    }
    TreeNode* makeTreeNode(int d) {
        TreeNode* node = NULL;
        if (d <= 0) return NULL;
        if (d > 1) {
            node = new TreeNode();
            node->left = makeTreeNode(d - 1);
            node->right = makeTreeNode(d - 1);
            return node;
        }
        if (leafs-- > 0) return new TreeNode();
        return NULL;
    }
    ListNode* fillData(TreeNode* node, ListNode *head) {
        if (node == NULL) return head;
        head = fillData(node->left, head);
        node->value = head->value;
        return fillData(node->right, head->next);
    }
public:
    TreeNode *sortedListToBST(ListNode *head) {
        TreeNode *root = NULL;
        depth = 0;
        leafs = 0;
        calcDepthAndLeafs(head);
        root = makeTreeNode(depth);
        fillData(root, head);
 
        return root;
    }
};
