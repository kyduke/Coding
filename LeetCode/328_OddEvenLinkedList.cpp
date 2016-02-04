// https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = NULL;
        ListNode* evenHead = NULL;
        ListNode* node;
        ListNode* oddNode;
        ListNode* evenNode;
        int n;
        
        node = head;
        if (node) {
            oddHead = node;
            oddNode = node;
            node = node->next;
        }
        
        if (node) {
            evenHead = node;
            evenNode = node;
            node = node->next;
        }
        
        n = 0;
        while (node) {
            if (n == 0) {
                n = 1;
                oddNode->next = node;
                oddNode = node;
            } else {
                n = 0;
                evenNode->next = node;
                evenNode = node;
            }
            node = node->next;
        }
        
        if (evenNode) {
            evenNode->next = NULL;
        }
        
        oddNode->next = evenHead;
        
        return oddHead;
    }
};

/*
1->2->3->4->5->NULL
=====
1->3->5->2->4->NULL
*/
