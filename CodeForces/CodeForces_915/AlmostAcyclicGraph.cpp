// http://codeforces.com/contest/915/problem/D
// Wrone answer
// Time limit exceeded

#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int SIZE = 100000;

struct Edge {
	int u;
	int v;
};

int visitedNode[501] = {0, };
int visitedEdge[SIZE] = {0, };
int activeEdge[501] = {0, };
vector<int> edges[501];
set<int> noneZeroEdges;
Edge arr[SIZE];
int circleCount;

void dfs(int u) {
	int i, j, k, v, k2, v2;
	bool isCircle;

	visitedNode[u] = 1;
	activeEdge[u] = -1;
	for (i = 0; i < edges[u].size(); i++) {
		k = edges[u][i];
		activeEdge[u] = k;
		v = arr[k].v;
		if (visitedNode[v] == 0) {
			dfs(v);
		} else {
			isCircle = true;
			k2 = k;
			v2 = v;
			while (v2 != u) {
				k2 = activeEdge[v2];
				if (k2 == -1) {
					isCircle = false;
					break;
				}
				v2 = arr[k2].v;
			}
			if (isCircle == true) {
				circleCount++;
				k2 = k;
				v2 = v;
				visitedEdge[k2]++;
				if (visitedEdge[k2] > 1) noneZeroEdges.insert(k2);
				while (v2 != u) {
					k2 = activeEdge[v2];
					visitedEdge[k2]++;
					if (visitedEdge[k2] > 1) noneZeroEdges.insert(k2);
					v2 = arr[k2].v;
				}
			}
		}
	}
}

bool solve(int n) {
	set<int>::iterator it;
	int i, count, weight;

	circleCount = 0;
	for (i = 1; i <= n; i++) {
		if (visitedNode[i] != 0) continue;
		dfs(i);
	}

	count = 0;
	weight = 0;
	for (it = noneZeroEdges.begin(); it != noneZeroEdges.end(); it++) {
		count++;
		weight += visitedEdge[ *it ] - 1;
	}

	return count <= 1 && (circleCount - weight) <= 1;
}

int main(int argc, char* argv[]) {
	int n, m, i, u, v;

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		arr[i].u = u;
		arr[i].v = v;
		edges[u].push_back(i);
	}

	if (solve(n) == true) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}

/*
3 4
1 2
2 3
3 2
3 1
=====
YES

5 6
1 2
2 3
3 2
3 1
2 1
4 5
=====
NO
*/
