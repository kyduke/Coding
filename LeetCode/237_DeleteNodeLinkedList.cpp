// https://leetcode.com/problems/delete-node-in-a-linked-list/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL || node->next == NULL) return;
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

void printList(ListNode* node) {
	while (node) {
		cout << node->val << " ";
		node = node->next;
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	Solution s;
	ListNode* head;

	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	printList(head);

	s.deleteNode(head->next->next->next);

	printList(head);

	return 0;
}
