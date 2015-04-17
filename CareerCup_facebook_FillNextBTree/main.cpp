#include <iostream>
#include <vector>

using namespace std;

struct Node {
	char name;
	Node* left;
	Node* right;
	Node* next;
};

void fillNext(Node* node, vector<Node*>& depthNodes, int depth) {
	Node* prev;

	if (node == NULL) return;
	
	if (depthNodes.size() > depth) {
		prev = depthNodes[depth];
		if (prev) {
			prev->next = node;
			cout << prev->name << " - " << node->name << "\n";
		}
		depthNodes[depth] = node;
	} else {
		depthNodes.push_back(node);
	}

	fillNext(node->left, depthNodes, depth + 1);
	fillNext(node->right, depthNodes, depth + 1);
}

int main(int argc, char* argv[]) {
	Node A, B, C, D, F, G, H, I;
	vector<Node*> depthNodes;

	A.name = 'A';
	A.left = &B;
	A.right = &C;
	A.next = NULL;

	B.name = 'B';
	B.left = &D;
	B.right = NULL;
	B.next = NULL;

	C.name = 'C';
	C.left = &F;
	C.right = &G;
	C.next = NULL;

	D.name = 'D';
	D.left = &H;
	D.right = &I;
	D.next = NULL;

	F.name = 'F';
	F.left = NULL;
	F.right = NULL;
	F.next = NULL;

	G.name = 'G';
	G.left = NULL;
	G.right = NULL;
	G.next = NULL;

	H.name = 'H';
	H.left = NULL;
	H.right = NULL;
	H.next = NULL;

	I.name = 'I';
	I.left = NULL;
	I.right = NULL;
	I.next = NULL;

	depthNodes.clear();
	fillNext(&A, depthNodes, 0);
	depthNodes.clear();

	return 0;
}
