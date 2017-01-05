// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        ListNode* n = NULL;
        ListNode* x = NULL;
        
        if (head && head->next) n = head->next;
        if (head) head->next = NULL;
        while (n) {
            if (n->next) {
                x = n->next;
            } else {
                x = NULL;
            }
            n->next = head;
            head = n;
            n = x;
        }
        
        return head;
    }
};
