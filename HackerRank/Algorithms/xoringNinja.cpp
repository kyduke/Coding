// https://www.hackerrank.com/challenges/xoring-ninja

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

const int DIVIDER = 1000000007;

UINT64 powerOfTwo(int n) {
	UINT64 powers;

	powers = 1;
	while (n--) {
		powers = (2 * powers) % DIVIDER;
	}

	return powers;
}

int main(int argc, char* argv[]) {
	int t, n, a, i;
	UINT64 ors, result, powers;

	cin >> t;
	while (t--) {
		cin >> n;

		ors = 0;
		i = 0;
		while (i < n) {
			cin >> a;
			ors |= a;
			i++;
		}

		powers = powerOfTwo(n - 1);
		
		result = (ors * powers) % DIVIDER;

		cout << result << "\n";
	}

	return 0;
}

/*
1
3
1 2 3
=====
12
*/
