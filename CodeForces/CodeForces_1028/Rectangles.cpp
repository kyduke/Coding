// https://codeforces.com/contest/1028/problem/C

#include <iostream>

using namespace std;

const int SIZE = 132674;

struct Node {
	int x1;
	int y1;
	int x2;
	int y2;
	bool empty;
};

Node arr[SIZE];
Node frontCache[SIZE];
Node backCache[SIZE];

Node solve(Node a, Node b) {
	Node node;

	if (a.empty == false && b.empty == false && a.x2 >= b.x1 && b.x2 >= a.x1 && a.y2 >= b.y1 && b.y2 >= a.y1) {
		node.x1 = max(a.x1, b.x1);
		node.y1 = max(a.y1, b.y1);
		node.x2 = min(a.x2, b.x2);
		node.y2 = min(a.y2, b.y2);
		node.empty = false;
	} else {
		node.empty = true;
	}

    return node;
}

int main(int argc, char** argv) {
	Node node;
	int n, i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d %d", &arr[i].x1, &arr[i].y1, &arr[i].x2, &arr[i].y2);
		arr[i].empty = false;
	}

	frontCache[0] = arr[0];
	for (i = 1; i < n; i++) {
		frontCache[i] = solve(frontCache[i - 1], arr[i]);
	}

	backCache[n - 1] = arr[n - 1];
	for (i = n - 2; i >= 0; i--) {
		backCache[i] = solve(backCache[i + 1], arr[i]);
	}

	if (backCache[1].empty == false) {
		printf("%d %d\n", backCache[1].x1, backCache[1].y1);
	} else if (frontCache[n - 2].empty == false) {
		printf("%d %d\n", frontCache[n - 2].x1, frontCache[n - 2].y1);
	} else {
		for (i = 1; i < n - 1; i++) {
			node = solve(frontCache[i - 1], backCache[i + 1]);
			if (node.empty == false) {
				printf("%d %d\n", node.x1, node.y1);
				break;
			}
		}
	}

	return 0;
}

/*
3
0 0 1 1
1 1 2 2
3 0 4 1
=====
1 1

3
0 0 1 1
0 1 1 2
1 0 2 1
=====
1 1

4
0 0 5 5
0 0 4 4
1 1 4 4
1 1 4 4
=====
1 1

5
0 0 10 8
1 2 6 7
2 3 5 6
3 4 4 5
8 1 9 2
=====
3 4
*/
