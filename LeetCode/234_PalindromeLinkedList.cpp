// https://leetcode.com/problems/palindrome-linked-list/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	ListNode* node;
	bool compareHeadAndTail(ListNode* tail) {
		if (tail == NULL) {
			return true;
		}

		if (compareHeadAndTail(tail->next) == false) {
			return false;
		}

		if (node->val != tail->val) {
			return false;
		}

		node = node->next;

		return true;
	}
public:
    bool isPalindrome(ListNode* head) {
		node = head;
		return compareHeadAndTail(head);
    }
};

void pushNode(ListNode* head, int n) {
	ListNode* node;

	if (head == NULL) return;

	node = head;
	while (node->next) {
		node = node->next;
	}
	node->next = new ListNode(n);
}

void removeAllNode(ListNode* node) {
	if (node == NULL) return;
	
	removeAllNode(node->next);
	delete node->next;
	node->next = NULL;
}

void printAllNode(ListNode* node) {
	if (node == NULL) {
		cout << "\n";
		return;
	}

	cout << node->val;
	printAllNode(node->next);
}

int main(int argc, char* argv[]) {
	ListNode* head;
	Solution s;

	head = new ListNode(7);
	pushNode(head, 3);
	pushNode(head, 5);
	pushNode(head, 6);
	pushNode(head, 8);

	printAllNode(head);
	cout << s.isPalindrome(head) << "\n";

	removeAllNode(head);
	delete head;
	head = NULL;

	head = new ListNode(7);
	pushNode(head, 3);
	pushNode(head, 5);
	pushNode(head, 3);
	pushNode(head, 7);

	printAllNode(head);
	cout << s.isPalindrome(head) << "\n";

	removeAllNode(head);
	delete head;
	head = NULL;

	return 0;
}
