// https://www.hackerrank.com/contests/round-2-holiday-cup/challenges/super-highways

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long UINT64;

const UINT64 MOD = 1000000009;

int main(int argc, char* argv[]) {
	int t;
	UINT64 n, nm, np, k, c, sum, ret;

	cin >> t;
	while (t--) {
		ret = 0;
		cin >> n >> k >> c;

		nm = (n - 1) % MOD;
		np = (n + 1) % MOD;
		n = n % MOD;
		k = k % MOD;
		c = c % MOD;
		ret = (n * nm / 2) % MOD;
		ret = (ret * c) % MOD;

		sum = (n * nm * np / 6) % MOD;
		ret = (sum * k + ret) % MOD;

		cout << ret << "\n";
	}

	return 0;
}

/*
1
3 1 1
=====
7
*/
