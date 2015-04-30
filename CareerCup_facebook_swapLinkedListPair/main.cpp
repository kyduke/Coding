//http://www.careercup.com/question?id=6313112158339072
#include <iostream>

using namespace std;

struct node {
	char data;
	node* next;
};

node* createNode(char d) {
	node* item = NULL;

	item = new node();
	item->data = d;
	item->next = NULL;

	return item;
}

void addNode(node* item, char d) {
	while (item) {
		if (item->next == NULL) {
			item->next = createNode(d);
			return;
		}
		item = item->next;
	}
}

void freeNodes(node* item) {
	node* curr = NULL;

	while (item) {
		curr = item;
		item = curr->next;
		curr->next = NULL;
		delete curr;
	}
}

void printNodes(node* item) {
	while (item) {
		cout << item->data;
		item = item->next;
		if (item) {
			cout << " -> ";
		} else {
			cout << "\n";
		}
	}
}

void swapPair(node* item) {
	node* a = NULL;
	node* b = NULL;
	char temp;

	while (item) {
		a = item;
		b = a->next;
		if (b) {
			item = b->next;
			temp = a->data;
			a->data = b->data;
			b->data = temp;
		} else {
			break;
		}
	}
}

int main(int argc, char* argv[]) {
	node* root = NULL;

	root = createNode('A');
	addNode(root, 'B');
	addNode(root, 'C');
	addNode(root, 'D');
	addNode(root, 'E');

	printNodes(root);

	swapPair(root);

	printNodes(root);

	freeNodes(root);
	root = NULL;
	printNodes(root);

	return 0;
}
