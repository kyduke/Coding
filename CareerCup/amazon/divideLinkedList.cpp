// http://careercup.com/question?id=4811161277038592

#include <iostream>
#include <math.h>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int v) : next(NULL) {
		val = v;
	}
};

bool isFibonacci(int n) {
	int k, r;

	k = n * n * 5 - 4;
	r = sqrt((double)k);
	if (r * r == k) return true;

	k = n * n * 5 + 4;
	r = sqrt((double)k);
	if (r * r == k) return true;

	return false;
}

void divideLinkedList(Node* node, Node** fRoot, Node** oRoot) {
	Node* fNode = NULL;
	Node* oNode = NULL;

	while (node) {
		if (isFibonacci(node->val) == true) {
			if (fNode == NULL) {
				*fRoot = node;
				fNode = *fRoot;
			} else {
				fNode->next = node;
				fNode = fNode->next;
			}
		} else {
			if (oNode == NULL) {
				*oRoot = node;
				oNode = *oRoot;
			} else {
				oNode->next = node;
				oNode = oNode->next;
			}
		}
		node = node->next;
	}
	fNode->next = NULL;
	oNode->next = NULL;
}

void addLinkedList(Node* node, int v) {
	while (node->next) {
		node = node->next;
	}

	node->next = new Node(v);
}

void printLinkedList(Node* node) {
	while (node) {
		cout << node->val << ",";
		node = node->next;
	}
	cout << "\n";
}

void freeLinkedList(Node* node) {
	if (node == NULL) return;
	freeLinkedList(node->next);
	delete node->next;
}

int main(int argc, char* argv[]) {
	Node* root = NULL;
	Node* fibonacciRoot = NULL;
	Node* otherRoot = NULL;

	root = new Node(0);
	addLinkedList(root, 1);
	addLinkedList(root, 2);
	addLinkedList(root, 3);
	addLinkedList(root, 4);
	addLinkedList(root, 5);
	addLinkedList(root, 6);
	addLinkedList(root, 7);
	addLinkedList(root, 8);
	addLinkedList(root, 9);

	divideLinkedList(root, &fibonacciRoot, &otherRoot);

	printLinkedList(root);
	printLinkedList(fibonacciRoot);
	printLinkedList(otherRoot);

	root = NULL;

	if (fibonacciRoot != NULL) {
		freeLinkedList(fibonacciRoot);
		delete fibonacciRoot;
		fibonacciRoot = NULL;
	}

	if (otherRoot != NULL) {
		freeLinkedList(otherRoot);
		delete otherRoot;
		otherRoot = NULL;
	}

	return 0;
}
