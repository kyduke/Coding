#include <iostream>

using namespace std;

struct Node {
	int val;
    Node* next;
};

Node* createNode(int val) {
	Node* node = new Node();
	node->val = val;
	node->next = NULL;
	return node;
}

Node* createLinkedList(int n) {
	Node* root = NULL;
	Node* node = NULL;
	int i;
	
	root = createNode(0);
	node = root;
	for (i = 1; i <= n; i++) {
		node->next = createNode(i);
		node = node->next;
	}
	
	return root;
}

void freeLinkedList(Node* node) {
	if (node != NULL) {
		freeLinkedList(node->next);
		delete node;
	}
}

void printLinkedList(Node* root) {
	while (root != NULL) {
		printf("%d", root->val);
		root = root->next;
		if (root != NULL) printf(" -> ");
	}
	printf("\n");
}

// 0 -> 1 -> 2 -> 3 -> 4 -> 5
// 0 -> 5 -> 1 -> 4 -> 2 -> 3
Node* foldLinkedList(Node* node, Node* parent, Node* root) {
	Node* left = NULL;
	Node* right = NULL;
	
	if (node == NULL) return root;
	
	left = foldLinkedList(node->next, node, root);
	if (left == NULL || left == node) return left;
	
	right = left->next;
	if (right == NULL || right == node) return right;
	
	if (parent != NULL) {
		left->next = node;
		node->next = right;
		parent->next = NULL;
	}
	
	return right;
}

int main(int argc, char** argv) {
	Node* root = NULL;
	int i;
	
	for (i = 0; i < 20; i++) {
		root = createLinkedList(i);
		printLinkedList(root);
		foldLinkedList(root, NULL, root);
		printLinkedList(root);
		freeLinkedList(root);
	}
	
	return 0;
}

/*
0
0
0 -> 1
0 -> 1
0 -> 1 -> 2
0 -> 2 -> 1
0 -> 1 -> 2 -> 3
0 -> 3 -> 1 -> 2
0 -> 1 -> 2 -> 3 -> 4
0 -> 4 -> 1 -> 3 -> 2
0 -> 1 -> 2 -> 3 -> 4 -> 5
0 -> 5 -> 1 -> 4 -> 2 -> 3
0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6
0 -> 6 -> 1 -> 5 -> 2 -> 4 -> 3
0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
0 -> 7 -> 1 -> 6 -> 2 -> 5 -> 3 -> 4
0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
0 -> 8 -> 1 -> 7 -> 2 -> 6 -> 3 -> 5 -> 4
0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
0 -> 9 -> 1 -> 8 -> 2 -> 7 -> 3 -> 6 -> 4 -> 5
0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
0 -> 10 -> 1 -> 9 -> 2 -> 8 -> 3 -> 7 -> 4 -> 6 -> 5
*/
