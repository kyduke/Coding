// http://careercup.com/question?id=5078919034175488

#include <iostream>
#include <set>

using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int v) : left(NULL), right(NULL) {
		value = v;
	}
};

void freeBT(Node* node) {
	if (node == NULL) return;
	freeBT(node->left);
	free(node->left);
	node->left = NULL;
	freeBT(node->right);
	free(node->right);
	node->right = NULL;
}

void makeIntegerArray(Node* node, set<int>& arr) {
	if (node == NULL) return;
	arr.insert(node->value);
	makeIntegerArray(node->left, arr);
	makeIntegerArray(node->right, arr);
}

bool haveSameIntegers(Node* a, Node* b) {
	set<int> arrA, arrB;
	set<int>::iterator itA, itB;

	makeIntegerArray(a, arrA);
	makeIntegerArray(b, arrB);

	if (arrA.size() != arrB.size()) return false;

	itA = arrA.begin();
	itB = arrB.begin();
	while (itA != arrA.end() && itB != arrB.end()) {
		if (*itA != *itB) return false;
		itA++;
		itB++;
	}

	return true;
}

int main(int argc, char* argv[]) {
	Node* rootA = NULL;
	Node* rootB = NULL;

	rootA = new Node(5);
	rootA->left = new Node(1);
	rootA->right = new Node(6);
	rootA->left->left = new Node(5);
	rootA->left->right = new Node(4);
	rootA->right->left = new Node(3);
	rootA->right->right = new Node(6);

	rootB = new Node(1);
	rootB->left = new Node(3);
	rootB->right = new Node(4);
	rootB->left->left = new Node(6);
	rootB->right->right = new Node(5);

	cout << haveSameIntegers(rootA, rootB) << "\n";

	freeBT(rootA);
	free(rootA);
	rootA = NULL;

	freeBT(rootB);
	free(rootB);
	rootB = NULL;

	return 0;
}
