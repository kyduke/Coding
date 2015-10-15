// https://algospot.com/judge/problem/read/QUADTREE

#include <iostream>

using namespace std;

struct Node {
	char c;
	Node* p0;
	Node* p1;
	Node* p2;
	Node* p3;
	Node() : p0(NULL), p1(NULL), p2(NULL), p3(NULL) {}
};

const int SIZE = 1001;

char buffer[SIZE];

int parseAndMakeQTree(Node* node, int i) {
	char c;

	if (node == NULL) return i;

	c = buffer[i];
	i++;
	if (c != 'x' && c != 'w' && c != 'b') return i;

	node->c = c;
	if (c == 'x') {
		node->p0 = new Node();
		i = parseAndMakeQTree(node->p0, i);

		node->p1 = new Node();
		i = parseAndMakeQTree(node->p1, i);

		node->p2 = new Node();
		i = parseAndMakeQTree(node->p2, i);

		node->p3 = new Node();
		i = parseAndMakeQTree(node->p3, i);
	}

	return i;
}

void printVerticalFlipAndDeleteQTree(Node* node) {
	if (node == NULL) return;

	cout << node->c;

	if (node->c == 'x') {
		printVerticalFlipAndDeleteQTree(node->p2);
		delete node->p2;

		printVerticalFlipAndDeleteQTree(node->p3);
		delete node->p3;

		printVerticalFlipAndDeleteQTree(node->p0);
		delete node->p0;

		printVerticalFlipAndDeleteQTree(node->p1);
		delete node->p1;
	}
}

void solve() {
	Node* root;

	root = new Node();

	parseAndMakeQTree(root, 0);
	printVerticalFlipAndDeleteQTree(root);
	cout << "\n";

	delete root;
}

int main(int argc, char* argv[]) {
	int C;

	cin >> C;
	while (C--) {
		cin >> buffer;
		solve();
	}

	return 0;
}

/*
4
w
xbwwb
xbwxwbbwb
xxwwwbxwxwbbbwwxxxwwbbbwwwwbb
=====
w
xwbbw
xxbwwbbbw
xxwbxwwxbbwwbwbxwbwwxwwwxbbwb
*/
