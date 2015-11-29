// https://www.hackerrank.com/contests/w18/challenges/rhombographs

#include <iostream>

using namespace std;

const int SIZE = 3500;

int maps[SIZE][SIZE];
int link[SIZE];

int getNodeCount(int n, int m, int x) {
	int node;

	node = x + 1;
	if (node < n) node = n;
	if (node % 2 == 1 && x % 2 == 1) node++;
	if (node > m) node = -1;

	return node;
}

void makeCircle(int node) {
	int i, j;

	for (i = 0; i < node; i++) {
		j = (i + 1) % node;
		maps[i][j] = 1;
		maps[j][i] = 1;
		link[i]++;
		link[j]++;
	}
}

void printGraph(int node, int x) {
	int i, j;

	cout << node << " " << (node * x / 2) << "\n";
	for (i = 0; i < node; i++) {
		for (j = i + 1; j < node; j++) {
			if (maps[i][j] == 0) continue;
			cout << i + 1 << " " << j + 1 << "\n";
		}
	}
}

void caseOne() {
	maps[0][1] = 1;
	maps[1][0] = 1;
	link[0]++;
	link[1]++;
}

void caseN(int node, int x) {
	int i, j, k, half, linkCount;

	makeCircle(node);
	linkCount = 2;

	if (linkCount == x) return;

	if (node % 2 == 0 && x % 2 == 1) {
		half = node / 2;
		for (i = 0; i < half; i++) {
			j = (i + half) % node;
			maps[i][j] = 1;
			maps[j][i] = 1;
			link[i]++;
			link[j]++;
		}
		linkCount++;
	}

	k = 2;
	while (linkCount < x) {
		for (i = 0; i < node; i++) {
			j = (i + k) % node;

			maps[i][j] = 1;
			maps[j][i] = 1;
			link[i]++;
			link[j]++;
		}
		linkCount += 2;
		k++;
	}
}

int main(int argc, char* argv[]) {
	int n, m, x, node;

	cin >> n >> m >> x;

	node = getNodeCount(n, m, x);
	if (node == -1) {
		cout << "-1 -1\n";
		return 0;
	}

	if (x == 1) {
		caseOne();
	} else {
		caseN(node, x);
	}

	printGraph(node, x);

	return 0;
}

/*
1 4 2
=====
4 4
1 2
2 4
1 3
3 4
*/
