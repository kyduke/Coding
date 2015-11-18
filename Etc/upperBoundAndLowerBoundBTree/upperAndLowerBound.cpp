#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int v) : value(v), left(NULL), right(NULL) {}
};

Node* findMin(Node* node) {
	if (node == NULL) return NULL;
	if (node->left) return findMin(node->left);
	return node;
}

Node* findMax(Node* node) {
	if (node == NULL) return NULL;
	if (node->right) return findMax(node->right);
	return node;
}

Node* lowerBound(Node* node, int n) {
	Node* ret = NULL;
	
	if (node == NULL) return NULL;
	
	if (node->value == n) {
		return findMax(node->left);
	} else if (node->value > n) {
		return lowerBound(node->left, n);
	} else {
		ret = lowerBound(node->right, n);
		if (ret != NULL) return ret;
	}
	
	return node;
}

Node* upperBound(Node* node, int n) {
	Node* ret = NULL;
	
	if (node == NULL) return NULL;
	
	if (node->value == n) {
		return findMin(node->right);
	} else if (node->value < n) {
		return upperBound(node->right, n);
	} else {
		ret = upperBound(node->left, n);
		if (ret != NULL) return ret;
	}
	
	return node;
}

void printNode(Node* node) {
	if (node == NULL) cout << "NULL\n";
	else cout << node->value << "\n";
}

int main(int argc, char* argv[]) {
	Node* root;
	Node* node;
	
	root = new Node(7);
	root->left = new Node(4);
	root->left->left = new Node(3);
	root->left->right = new Node(6);
	root->left->left->left = new Node(2);
	root->right = new Node(10);
	root->right->left = new Node(9);
	root->right->right = new Node(12);
	
	node = lowerBound(root, 1);
	printNode(node);
	
	node = lowerBound(root, 5);
	printNode(node);
	
	node = lowerBound(root, 7);
	printNode(node);
	
	node = lowerBound(root, 8);
	printNode(node);
	
	node = lowerBound(root, 11);
	printNode(node);
	
	node = lowerBound(root, 100);
	printNode(node);
	
	node = upperBound(root, 1);
	printNode(node);
	
	node = upperBound(root, 5);
	printNode(node);
	
	node = upperBound(root, 7);
	printNode(node);
	
	node = upperBound(root, 8);
	printNode(node);
	
	node = upperBound(root, 11);
	printNode(node);
	
	node = upperBound(root, 100);
	printNode(node);

    return 0;
}
