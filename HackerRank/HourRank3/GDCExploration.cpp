// https://www.hackerrank.com/contests/hourrank-3/challenges/divisor-exploration-5

#include <iostream>

using namespace std;

typedef long long INT64;

int primes[100];

INT64 gdc(INT64 a, INT64 b) {
	int t;

	if (a == 1 || b == 1) return 1;

	if (a < 100 || b < 100) {
		if (a < b) {
			t = a;
			a = b;
			b = t;
		}

		if (primes[b] == 0 && a % b == 0) {
			return b;
		}
	}

	while (a && b) {
		if (a > b) {
			a -= b;
		} else {
			b -= a;
		}
	}

	return a + b;
}

int main(int argc, char* argv[]) {
	INT64 i, j, n, a, b, c;

	cin >> n >> a >> b;

	for (i = 2; i < 100; i++) {
		if (primes[i] == 1) continue;
		for (j = i + i; j < 100; j += i) {
			primes[j] = 0;
		}
	}

	c = gdc(a, b);
	for (i = 0; i < c; i++) {
		cout << n;
	}
	cout << "\n";

	return 0;
}

/*
123 2 3
=====
123
*/
