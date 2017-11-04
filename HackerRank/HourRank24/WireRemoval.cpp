// https://www.hackerrank.com/contests/hourrank-24/challenges/wire-removal/problem

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 100001;

struct Node {
	UINT64 k;
	int c;
	int p;
	int d;
	int t;
};
struct Compare {
    bool operator() (const Node& a, const Node& b) {
        return a.k < b.k;
    }
};

vector<int> child[SIZE];
UINT64 sums[SIZE] = {0, };
int depths[SIZE] = {0, };
int used[SIZE] = {0, };

double solve(UINT64 n) {
	priority_queue<Node, vector<Node>, Compare> q;
	Node node;
	UINT64 k, k2, sum, dd;
	int c, p, d, t, i, j;

	node.k = 1;
	node.c = 1;
	node.p = 0;
	node.d = 0;
	node.t = 0;
	q.push(node);
	while (!q.empty()) {
		node = q.top();
		q.pop();
		if (node.t == 1) {
			sums[node.p] += sums[node.c];
			continue;
		}

		k2 = node.k;
		c = node.c;
		p = node.p;
		d = node.d;
		t = node.t;

		sums[c] = 1;
		depths[c] = d;
		used[c] = 1;

		k = (UINT64)(d + 1) * (UINT64)1000000;
		for (i = 0; i < child[c].size(); i++) {
			j = child[c][i];
			if (used[j] == 1) continue;
			node.k = k + (UINT64)j;
			node.c = j;
			node.p = c;
			node.d = d + 1;
			node.t = 0;
			q.push(node);
		}
		node.k = k2;
		node.c = c;
		node.p = p;
		node.t = 1;
		q.push(node);
	}

	sum = 0;
	dd = 0;
	for (i = 2; i <= n; i++) {
		sum += (n - sums[i]) * depths[i];
		dd += depths[i];
	}

	return (double)sum / (double)(dd);
}

int main(int argc, char* argv[]) {
	int n, u, v, i;

	scanf("%d", &n);
	for (i = 0; i < n - 1; i++) {
		scanf("%d %d", &u, &v);
		child[u].push_back(v);
		child[v].push_back(u);
	}
	printf("%.10f\n", solve(n));

	return 0;
}

/*
3
1 2
1 3
=====
2.0000000000

7
1 2
1 3
2 4
2 5
3 6
3 7
=====
5.6000000000
*/
