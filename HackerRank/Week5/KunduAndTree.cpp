// https://www.hackerrank.com/contests/w5/challenges/kundu-and-tree

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 100002;
const UINT64 MOD = 1000000007;

vector<int> links[SIZE];
int visited[SIZE] = {0, };
UINT64 groupCount[SIZE] = {0, };
UINT64 sumOfGroupCount[SIZE] = {0, };
UINT64 countMultiSum[SIZE] = {0, };
UINT64 sumOfCountMultiSum[SIZE] = {0, };

int dfs(int k) {
	int ans, i;

	ans = 0;
	if (visited[k] == 1) return ans;

	ans = 1;
	visited[k] = 1;
	for (i = 0; i < links[k].size(); i++) {
		ans += dfs(links[k][i]);
	}

	return ans;
}

int solve(int n) {
	int ans, group, i, c;
	UINT64 sum;

	ans = 0;

	group = 0;
	for (i = 1; i <= n; i++) {
		c = dfs(i);
		if (c > 0) {
			group++;
			groupCount[group] = c;
		}
	}

	sum = groupCount[group];
	for (i = group - 1; i > 0; i--) {
		sumOfGroupCount[i] = sum;
		sum += groupCount[i];
	}

	for (i = 1; i < group - 1; i++) {
		countMultiSum[i] = (groupCount[i + 1] * sumOfGroupCount[i + 1]) % MOD;
	}

	sum = 0;
	for (i = group - 1; i > 0; i--) {
		sum += countMultiSum[i];
		sumOfCountMultiSum[i] = sum;
	}

	ans = 0;
	for (i = 1; i < group - 1; i++) {
		ans = (ans + (groupCount[i] * sumOfCountMultiSum[i])) % MOD;
	}

	return ans;
}

int main(int argc, char* argv[]) {
	int n, i, u, v;
	char c;

	scanf("%d", &n);
	for (i = 0; i < n - 1; i++) {
		scanf("%d %d %c", &u, &v, &c);
		if (c == 'b') {
			links[u].push_back(v);
			links[v].push_back(u);
		}
	}
	printf("%d\n", solve(n));

	return 0;
}

/*
5
1 2 b
2 3 r
3 4 r
4 5 b
=====
4
*/
