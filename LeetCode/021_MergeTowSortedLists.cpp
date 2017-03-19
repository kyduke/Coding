// https://leetcode.com/problems/merge-two-sorted-lists/#/description

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* root = NULL;
        ListNode* node = NULL;
        
        if (l1 == NULL && l2 == NULL) return root;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        if (l1->val <= l2->val) {
            root = l1;
            l1 = l1->next;
        } else {
            root = l2;
            l2 = l2->next;
        }
        node = root;
        while (true) {
            if (l1 == NULL) {
                node->next = l2;
                break;
            } else if (l2 == NULL) {
                node->next = l1;
                break;
            } else {
                if (l1->val <= l2->val) {
                    node->next = l1;
                    l1 = l1->next;
                } else {
                    node->next = l2;
                    l2 = l2->next;
                }
                node = node->next;
            }
        }
        
        return root;
    }
};
