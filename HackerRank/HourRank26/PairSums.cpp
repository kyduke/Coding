// https://www.hackerrank.com/contests/hourrank-26/challenges/pair-sums
// Timeout

#include <iostream>

using namespace std;

typedef long long INT64;

const int SIZE = 500001;

INT64 arr[SIZE] = {0, };
INT64 dp[2][SIZE] = {0, };

INT64 solve(INT64 n) {
	INT64 ans, curr, prev, i, j, sum;

	ans = 0;

	for (i = n - 1; i >= 0; i--) {
		curr = i % 2;
		prev = (i + 1) % 2;
		sum = 0;
		for (j = i + 1; j < n; j++) {
			sum += arr[j];
			dp[curr][j - i] = dp[prev][j - i - 1] + (arr[i] * sum);
			ans = max(ans, dp[curr][j - i]);
		}
	}

	return ans;
}

int main(int argc, char* argv[]) {
	INT64 n, i;

	scanf("%lld", &n);
	for (i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	printf("%lld\n", solve(n));

	return 0;
}

/*
6
-3 7 -2 3 5 -2
=====
41

10
5 7 -5 6 3 9 -8 2 -1 10
=====
200
*/
