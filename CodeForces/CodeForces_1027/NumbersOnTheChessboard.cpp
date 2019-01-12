// https://codeforces.com/contest/1027/problem/B

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

int main(int argc, char** argv) {
	int in, q, ix, iy;
	UINT64 n, x, y;
	UINT64 ans, nnh, s;
	
	scanf("%d %d", &in, &q);
	n = in;
	nnh = (n * n) / 2;
	while (q--) {
		scanf("%d %d", &ix, &iy);
		x = ix;
		y = iy;
		s = x + y;
		if (s % 2 == 0) {
			ans = 0;
			ans += ((x - 1) / 2) * n;
			if (x % 2 == 0) {
				ans += n / 2;
				if (n % 2 == 1) ans++;
			}
			ans += (y + 1) / 2;
		} else {
			ans = nnh;
			if (n % 2 == 1) ans++;
			ans += ((x - 1) / 2) * n;
			if (x % 2 == 0) {
				ans += n / 2;
			}
			ans += (y + 1) / 2;
		}
		cout << ans << "\n";
	}
	
	return 0;
}

/*
4 5
1 1
4 4
4 3
3 2
2 4
=====
1
8
16
13
4

5 4
2 1
4 2
3 3
3 4
=====
16
9
7
20
*/
