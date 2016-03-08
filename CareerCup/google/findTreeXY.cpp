// https://careercup.com/question?id=5691211923849216

#include <iostream>
#include <stack>
#include <set>

using namespace std;

struct Node {
	int x;
	int y;
	Node* child;
	Node* sibling;
	Node(int vx, int vy): child(NULL), sibling(NULL) {
		x = vx;
		y = vy;
	}
};

struct WorkingNode {
	Node* node;
	int depth;
	int state;
};

void freeNodes(Node* node) {
	if (node == NULL) return;

	freeNodes(node->child);
	delete node->child;

	freeNodes(node->sibling);
	delete node->sibling;
}

bool find(Node* root, int x, int y) {
	stack<WorkingNode> stk;
	WorkingNode w;
	set<int> xs, ys;

	w.node = root;
	w.depth = 0;
	w.state = 0;
	stk.push(w);

	while (!stk.empty()) {
		w = stk.top();
		stk.pop();
		if (w.node == NULL) continue;
		
		if (w.state == 0) {
			if (w.node->x == x) {
				if (ys.find(w.depth) != ys.end()) return true;
				xs.insert(w.depth);
			}
			if (w.node->y == y) {
				if (xs.find(w.depth) != xs.end()) return true;
				ys.insert(w.depth);
			}
			w.state = 1;
			stk.push(w);
			w.node = w.node->child;
			w.depth++;
			w.state = 0;
			stk.push(w);
		} else {
			w.node = w.node->sibling;
			w.state = 0;
			stk.push(w);
		}
	}

	return false;
}

int main(int argc, char* argv[]) {
	Node* root;

	root = new Node(1, 120);
	root->child = new Node(5, 15);
	root->child->sibling = new Node(30, 70);
	root->child->sibling->sibling = new Node(80, 110);
	root->child->child = new Node(35, 40);
	root->child->child->sibling = new Node(45, 50);
	root->child->child->sibling->sibling = new Node(55, 65);
	root->child->sibling->sibling->child = new Node(90, 100);

	cout << find(root, 45, 100) << "\n";
	cout << find(root, 30, 100) << "\n";
	cout << find(root, 30, 70) << "\n";
	cout << find(root, 70, 30) << "\n";

	freeNodes(root);
	delete root;

	return 0;
}
