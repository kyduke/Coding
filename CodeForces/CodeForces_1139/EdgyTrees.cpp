// http://codeforces.com/contest/1139/problem/C
// Tutorial: http://codeforces.com/blog/entry/66101

#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long INT64;
 
const int SIZE = 100002;
const int MOD = 1000000007;
 
vector<int> arr[SIZE];
int visited[SIZE] = {0, };
int cnt;
 
int pow(INT64 a, INT64 b, INT64 m) {
	int ans;
	
	ans = 1;
	while (b) {
		if (b & 1) {
			ans = (ans * a) % m;
		}
		a = (a * a) % m;
		b /= 2;
	}
	
	return ans;
}
 
void dfs(int u) {
	int i;
	
	if (visited[u] == 1) {
		return;
	}
	visited[u] = 1;
	
	cnt++;
	for (i = 0; i < arr[u].size(); i++) {
		dfs(arr[u][i]);
	}
}
 
int main() {
	int ans, n, k, u, v, x, i;
	
	scanf("%d %d", &n, &k);
	ans = pow(n, k, MOD);
	
	for (i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &u, &v, &x);
		if (x == 1) {
			continue;
		}
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	
	for (i = 1; i <= n; i++) {
		cnt = 0;
		dfs(i);
		ans -= pow(cnt, k, MOD);
		ans = (ans + MOD) % MOD;
	}
	
	printf("%d\n", ans);
	
	return 0;
}

/*
4 4
1 2 1
2 3 1
3 4 1
==========
252

4 6
1 2 0
1 3 0
1 4 0
==========
0

3 5
1 2 1
2 3 0
==========
210
*/
