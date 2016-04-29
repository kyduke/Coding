// https://careercup.com/question?id=5702478461927424

#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* next;
	Node(int v) : value(v), next(NULL) {}
};

void freeNodes(Node* node) {
	if (node == NULL) return;

	freeNodes(node->next);

	delete node->next;
}

void printNodes(Node* node) {
	while (node) {
		cout << node->value << " ";
		node = node->next;
	}
}

Node* mergeLists(Node* a, Node* b) {
	Node* ret;
	Node* node;

	if (a == NULL && b == NULL) return ret;

	ret = new Node(0);
	node = ret;

	while (a || b) {
		if (a == NULL) {
			node->value = b->value;
			b = b->next;
			if (b) {
				node->next = new Node(0);
				node = node->next;
			}
		} else if (b == NULL) {
			node->value = a->value;
			a = a->next;
			if (a) {
				node->next = new Node(0);
				node = node->next;
			}
		} else {
			if (a->value <= b->value) {
				node->value = a->value;
				a = a->next;
			} else {
				node->value = b->value;
				b = b->next;
			}
			node->next = new Node(0);
			node = node->next;
		}
	}

	return ret;
}

int main(int argc, char* argv[]) {
	Node* a;
	Node* b;
	Node* result;

	a = new Node(3);
	a->next = new Node(5);
	a->next->next = new Node(7);

	b = new Node(4);
	b->next = new Node(8);
	b->next->next = new Node(10);

	result = mergeLists(a, b);

	printNodes(a);
	cout << "\n";
	printNodes(b);
	cout << "\n";
	printNodes(result);
	cout << "\n";

	freeNodes(a);
	delete a;
	freeNodes(b);
	delete b;
	freeNodes(result);
	delete result;

	return 0;
}

