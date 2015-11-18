// https://projecteuler.net/problem=129

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 19;

UINT64 repunits[SIZE];

void fillRepunit() {
	int i;

	repunits[0] = 1;
	for (i = 1; i < SIZE; i++) {
		repunits[i] = repunits[i - 1] * 10 + 1;
	}
}

int gdc(int a, int b) {
	while (a && b) {
		if (a > b) a -= b;
		else b -= a;
	}

	return a + b;
}

void solve() {
	int n, i, c;

	for (n = 1; n < 100; n++) {
		if (gdc(n, 10) == 1) {
			c = 0;
			for (i = 0; i < SIZE; i++) {
				if (repunits[i] % n == 0) {
					c = i + 1;
					break;
				}
			}
			if (c > 0) cout << n << ": " << c << "\n";
		}
	}
}

int main(int argc, char* ragv[]) {
	fillRepunit();
	solve();

	return 0;
}
