// https://codeforces.com/contest/1061/problem/C

#include <iostream>
#include <set>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 1000001;
const UINT64 MOD = 1000000007;

int arr[SIZE];
UINT64 dp[SIZE];

int main() {
	set<int> s;
	set<int>::reverse_iterator it;
	int n, i, j;
	UINT64 ans;
	
	scanf("%d", &n);
	dp[0] = 1;
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		s.clear();
		for (j = 1; j * j <= arr[i]; j++) {
			if (arr[i] % j == 0) {
				s.insert(j);
				s.insert(arr[i] / j);
			}
		}
		for (it = s.rbegin(); it != s.rend(); it++) {
			dp[*it] = (dp[*it] + dp[*it - 1]) % MOD;
		}
	}
	
	ans = 0;
	for (i = 1; i <= n; i++) {
		ans = (ans + dp[i]) % MOD;
	}
	
	printf("%d\n", (int)ans);

	return 0;
}

/*
2
1 2
=====
3
5
2 2 1 22 14
=====
13
*/
