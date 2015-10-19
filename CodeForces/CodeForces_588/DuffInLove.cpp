// http://codeforces.com/problemset/problem/588/B

#include <iostream>

typedef unsigned long long UINT64;

using namespace std;

UINT64 solve(UINT64 n) {
	UINT64 i, s;

	for (i = 2; i < n; i++) {
		s = i * i;
		if (s > n) break;
		while (n % s== 0) {
			n /= i;
		}
	}

	return n;
}

int main(int argc, char* argv[]) {
	UINT64 n;

	cin >> n;
	cout << solve(n) << "\n";

	return 0;
}

/*
10
=====
10

12
=====
6
*/
