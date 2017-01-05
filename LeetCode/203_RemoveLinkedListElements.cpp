// https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = NULL;
        ListNode* node = NULL;
        while (head && head->val == val) {
            head = head->next;
        }
        prev = head;
        if (head) node = head->next;
        while (node) {
            if (node->val == val) {
                prev->next = node->next;
            } else {
                prev = node;
            }
            node = node->next;
        }
        return head;
    }
};
