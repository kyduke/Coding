// http://codeforces.com/contest/919/problem/D

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 300003;

char str[SIZE];
vector<int> edges[SIZE];
int dp[SIZE][26] = {0, };
int done[SIZE][26] = {0, };
int visited[SIZE] = {0, };
int current[SIZE] = {0, };

int dfs(int v) {
	int i, u;
	if (visited[v] == 1) {
		return current[v];
	}

	visited[v] = 1;
	current[v] = 1;
	for (i = 0; i < edges[v].size(); i++) {
		if (dfs(edges[v][i]) == 1) {
			return 1;
		}
	}
	current[v] = 0;

	return 0;
}

int solve(int v, char c) {
	int i, u;

	if (done[v][c] == 1) {
		return dp[v][c];
	}

	done[v][c] = 1;
	for (i = 0; i < edges[v].size(); i++) {
		u = edges[v][i];
		dp[v][c] = max(dp[v][c], solve(u, c));
	}
	if (c == str[v]) {
		dp[v][c]++;
	}

	return dp[v][c];
}

int main(int argc, char* argv[]) {
	int n, m, i, j, u, v, ans;

	scanf("%d %d", &n, &m);
	scanf("%s", str);

	for (i = 0; i < n; i++) {
		str[i] -= 'a';
	}

	for (i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		u--;
		v--;
		edges[u].push_back(v);
	}

	for (i = 0; i < n; i++) {
		if (visited[i] == 0 && dfs(i) == 1) {
			printf("-1\n");
			return 0;
		}
	}

	ans = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 26; j++) {
			ans = max(ans, solve(i, j));
		}
	}
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
