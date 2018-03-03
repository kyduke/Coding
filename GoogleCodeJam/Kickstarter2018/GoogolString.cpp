// https://code.google.com/codejam/contest/4374486/dashboard#s=p1

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

int main(int argc, char** argv) {
	int t, i, ans;
	UINT64 k, x;

	scanf("%d", &t);
	for (i = 1; i <=t; i++) {
		scanf("%llu", &k);

		ans = 0;
		x = 1;
		while (x < k) x *= 2;

		while (k != 0) {
			if (k < x) {
				ans = 0;
			} else if (k > x) {
				ans = 1;
				k -= x;
			} else {
				k -= x;
			}
			x /= 2;
		}

		printf("Case #%d: %d\n", i, ans);
	}

	return 0;
}

/*
4
1
2
3
10
=====
Case #1: 0
Case #2: 0
Case #3: 1
Case #4: 0
*/
