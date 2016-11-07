// https://www.hackerrank.com/contests/hourrank-14/challenges/beautiful-days-at-the-movies

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

UINT64 reverse(UINT64 n) {
	UINT64 r;

	r = 0;
	while (n) {
		r = r * 10 + n % 10;
		n /= 10;
	}

	return r;
}

int solve(UINT64 i, UINT64 j, UINT64 k) {
	UINT64 n, r, t;
	int ans;

	ans = 0;
	for (n = i; n <= j; n++) {
		r = reverse(n);
		if (n > r) {
			t = n - r;
		} else {
			t = r - n;
		}
		if (t % k == 0) ans++;
	}

	return ans;
}

int main(int argc, char* argv[]) {
	UINT64 i, j, k;

	cin >> i >> j >> k;

	cout << solve(i, j, k) << "\n";

	return 0;
}

/*
20 23 6
=====
2
*/
