// https://www.hackerrank.com/contests/w6/challenges/consecutive-subsequences

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 1000001;

UINT64 sum[SIZE];
UINT64 cnt[100];

int main(int argc, char* argv[]) {
	int t, n, k, i, a;
	UINT64 ans;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);

		for (i = 0; i < k; i++) {
			cnt[i] = 0;
		}

		sum[0] = 0;
		for (i = 1; i <= n; i++) {
			scanf("%d", &a);
			sum[i] = (sum[i - 1] + a) % k;
			cnt[ sum[i] ]++;
		}

		ans = 0;
		for (i = 0; i < k; i++) {
			ans += (cnt[i] * (cnt[i] - 1)) / 2;
		}
		ans += cnt[0];

		printf("%llu\n", ans);
	}

	return 0;
}

/*
2
5 3
1 2 3 4 1
6 2
1 2 1 2 1 2
=====
4
9
*/
