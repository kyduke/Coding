// http://codeforces.com/contest/919/problem/D

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INFINITY = 2000000000;
const int SIZE = 300003;

struct Node {
	int c;
	int v;
	int x;
};

char str[SIZE];
vector<int> edges[SIZE];
int arr[SIZE][26] = {0, };
int loop[SIZE] = {0, };

void solve(int n) {
	queue<Node> q;
	Node node;
	int i, j, k, c, v, x, u, p, z;

	k = 0;
	for (i = 0; i < n; i++) {
		node.c = 1;
		node.v = i;
		node.x = -1;
		q.push(node);
		while (!q.empty()) {
			node = q.front();
			q.pop();
			
			c = node.c;
			v = node.v;
			x = node.x;
			if (c > n) {
				if (x >= 0) {
					loop[x] = 1;
				}
				continue;
			}

			if (x == -1) {
				x = k;
				k++;
			}
			arr[x][ str[v] - 'a' ]++;
			p = x;

			for (j = 0; j < edges[v].size(); j++) {
				u = edges[v][j];
				if (x == -1) {
					x = k;
					k++;
				}
				if (x != p) {
					for (z = 0; z < 26; z++) {
						arr[x][z] = arr[p][z];
					}
				}
				node.c = c + 1;
				node.v = u;
				node.x = x;
				q.push(node);
				x = -1;
			}
		}
	}
}

int main(int argc, char* argv[]) {
	int n, m, i, j, u, v, ans;

	scanf("%d %d", &n, &m);
	scanf("%s", str);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		u--;
		v--;
		edges[u].push_back(v);
	}

	solve(n);

	ans = 0;
	for (i = 0; i <= n; i++) {
		if (loop[i] == 1) continue;
		for (j = 0; j < 26; j++) {
			ans = max(ans, arr[i][j]);
		}
	}
	if (ans == 0) ans = -1;
	printf("%d\n", ans);

	return 0;
}

/*
5 4
abaca
1 2
1 3
3 4
4 5
=====
3

6 6
xzyabc
1 2
3 1
2 3
5 4
4 3
6 4
=====
-1

10 14
xzyzyzyzqx
1 2
2 4
3 5
4 5
2 6
6 8
6 5
2 10
3 9
10 9
4 6
1 10
2 8
3 7
=====
4
*/
