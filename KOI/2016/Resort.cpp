// https://www.acmicpc.net/problem/13302
// 한국정보올림피아드 2016 고등부 리조트

#include <iostream>

using namespace std;

const int SIZE = 111;
const int MAX = 1000000000;

int arr[SIZE] = {0, };
int dp[SIZE][SIZE] = {0, };

int solve(int n) {
	int ans, i, j;

	for (i = 0; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			dp[i][j] = MAX;
		}
	}
	dp[0][0] = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (arr[i + 1] == 1) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			}
			if (j >= 3) {
				dp[i + 1][j - 3] = min(dp[i + 1][j - 3], dp[i][j]);
			}
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 10000);
			
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 25000);
			dp[i + 2][j + 1] = min(dp[i + 2][j + 1], dp[i][j] + 25000);
			dp[i + 3][j + 1] = min(dp[i + 3][j + 1], dp[i][j] + 25000);
			
			dp[i + 1][j + 2] = min(dp[i + 1][j + 2], dp[i][j] + 37000);
			dp[i + 2][j + 2] = min(dp[i + 2][j + 2], dp[i][j] + 37000);
			dp[i + 3][j + 2] = min(dp[i + 3][j + 2], dp[i][j] + 37000);
			dp[i + 4][j + 2] = min(dp[i + 4][j + 2], dp[i][j] + 37000);
			dp[i + 5][j + 2] = min(dp[i + 5][j + 2], dp[i][j] + 37000);
		}
	}

	ans = MAX;
	for (i = 0; i < n; i++) {
		ans = min(ans, dp[n][i]);
	}

	return ans;
}

int main(int argc, char* argv[]) {
	int n, m, i;

	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d", &i);
		arr[i] = 1;
	}

	printf("%d\n", solve(n));

	return 0;
}

/*
13 5
4 6 7 11 12
=====
62000

50 10
3 5 7 11 15 16 22 23 24 34
=====
288000
*/
