// https://codeforces.com/contest/1061/problem/C
// Editorial: https://codeforces.com/blog/entry/63384
// Time limit exceeded 

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

const UINT64 DIV = 10000007;
const int SIZE = 100001;

UINT64 dp[2][SIZE] = {0, };
int arr[SIZE] = {0, };

int main() {
	int n, i, j;
	UINT64 ans;
	
	scanf("%d", &n);
	dp[0][0] = 1;
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		dp[0][i] = 1;
	}
	
	ans = 0;
	for (i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			dp[0][i - 1] = 0;
			for (j = i; j <= n; j++) {
				dp[0][j] = dp[0][j - 1];
				if (arr[j] % i == 0) {
					ans = (ans + dp[1][j - 1]) % DIV;
					dp[0][j] = (dp[0][j] + dp[1][j - 1]) % DIV;
				}
			}
		} else {
			dp[1][i - 1] = 0;
			for (j = i; j <= n; j++) {
				dp[1][j] = dp[1][j - 1];
				if (arr[j] % i == 0) {
					ans = (ans + dp[0][j - 1]) % DIV;
					dp[1][j] = (dp[1][j] + dp[0][j - 1]) % DIV;
				}
			}
		}
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
