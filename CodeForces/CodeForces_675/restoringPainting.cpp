// http://codeforces.com/contest/675/problem/B

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

UINT64 solveN(int n, int a, int b, int c, int d) {
	int i, k, x;
	UINT64 answer;

	answer = 0;
	k = a + b + n;
	for (i = a + b + 1; i <= k; i++) {
		x = i - a - c;
		if (x <= 0 || x > n) continue;
		x = i - b - d;
		if (x <= 0 || x > n) continue;
		x = i - c - d;
		if (x <= 0 || x > n) continue;
		answer += n;
	}

	return answer;
}

UINT64 solve(int n, int a, int b, int c, int d) {
	int small, big, diff;

	small = a + b;
	big = a + b;
	small = min(small, a + c);
	big = max(big, a + c);
	small = min(small, b + d);
	big = max(big, b + d);
	small = min(small, c + d);
	big = max(big, c + d);

	diff = big - small;
	if (diff >= n) return 0;

	return (UINT64)n * (n - diff);
}

int main(int argc, char* argv[]) {
	int n, a, b, c, d;

	cin >> n >> a >> b >> c >> d;
	cout << solve(n, a, b, c, d) << "\n";

	return 0;
}

/*
2 1 1 1 2
=====
2

3 3 1 2 3
=====
6
*/
