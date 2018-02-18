// http://codeforces.com/contest/938/problem/C

#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long UINT64;

void solve(UINT64 x) {
	UINT64 a, b, c, d, l, r;

    a = (UINT64)sqrt((double)x);
	while (true) {
		a++;
		b = a / 2;
		if (b == 0) b = 1;

		c = a * a - b * b;
		if (c > x) break;

		b = a;

		l = 1;
		r = b;
		while (l <= r) {
			b = (l + r) / 2;
			d = a / b;
			c = a * a - d * d;
			if (c == x) {
				b = a / d;
				printf("%d %d\n", (int)a, (int)b);
				return;
			}
			if (l == r) break;
			if (c < x) {
				if (l == b) {
					l++;
				} else {
					l = b;
				}
			} else {
				r = b;
			}
		}
	}
    
	printf("-1\n");
}

int main(int argc, char* argv[]) {
	int t, x;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &x);
		solve(x);
	}

	return 0;
}

/*
3
21
0
1
=====
5 2
1 1
-1
*/
