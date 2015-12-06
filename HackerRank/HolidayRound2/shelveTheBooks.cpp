// https://www.hackerrank.com/contests/round-2-holiday-cup/challenges/shelve-the-books

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

const UINT64 DIVIDER = 1000000007;
const int SIZE = 1000001;

UINT64 c[SIZE];
UINT64 z[SIZE];

int main(int argc, char* argv[]) {
	int t, n, k;

	c[0] = 1;
	z[0] = 1;
	for (k = 1; k < SIZE; k++) {
		c[k] = (c[k - 1] * k * 8) % DIVIDER;
		z[k] = (z[k - 1] * k * 24) % DIVIDER;
	}

	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (n == 1) {
			cout << z[k] << "\n";
        } else if (n == k) {
            cout << (c[k] * 3) % DIVIDER << "\n";
        } else {
			cout << c[k] << "\n";
		}
	}

	return 0;
}

/*
1
10 1
=====
8
*/
