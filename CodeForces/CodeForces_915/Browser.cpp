// http://codeforces.com/contest/915/problem/B

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int n, p, l, r, a, b, ans, dl, dr;

	scanf("%d %d %d %d", &n, &p, &l, &r);

	ans = 0;
	a = 1;
	b = n;
	if (p < l) {
		ans += l - p;
		p = l;
	} else if (p > r) {
		ans += p - r;
		p = r;
	}
	while (a < l || b > r) {
		dl = p - l;
		dr = r - p;
		if (l < p && p < r) {
			if (a < l && b > r) {
				if (dl <= dr) {
					ans += dl + 1;
					a = l;
					p = l;
				} else {
					ans += dr + 1;
					b = r;
					p = r;
				}
			} else if (a < l) {
				ans += dl + 1;
				a = l;
				p = l;
			} else if (b > r) {
				ans += dr + 1;
				b = r;
				p = r;
			}
		} else if (l == p) {
			if (a < l) {
				ans++;
				a = l;
			} else if (b > r) {
				ans += dr + 1;
				b = r;
				p = r;
			}
		} else if (p == r) {
			if (b > r) {
				ans++;
				b = r;
			} else if (a < l) {
				ans += dl + 1;
				a = l;
				p = l;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}

/*
6 3 2 4
=====
5

6 3 1 3
=====
1

5 2 1 5
=====
0

5 2 3 4
=====
4

5 5 1 1
=====
5

1 1 1 1
=====
0
*/
