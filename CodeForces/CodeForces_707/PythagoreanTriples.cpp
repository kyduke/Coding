// http://codeforces.com/contest/707/problem/C
// Pythagorean Triples
// a is odd number, m = (a + 1) / 2, n = (a - 1) / 2, m^2 - n^2 = (a^2 + 2a + 1) / 4 - (a^2 - 2a + 1) / 4 = a
// a = m^2 - n^2, b = 2mn, c = m^2 + n^2, (a, b, c) is Pythagorian triples
// first Pythagorian triples are (3, 4, 5), 9x^2 + 16x^2 = 25X^2 => 9 + 16 = 25
// a is odd number, b is even number, 0, 1, 2, a, 4, a, 2a, a, 4b, a...

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

void solve(int a) {
	UINT64 m, n, b, c;

	if (a < 3) {
		cout << -1;
	} else if (a % 4 == 0) {
		a /= 4;
		b = 3 * a;
		c = 5 * a;
		cout << b << " " << c;
	} else if (a % 5 == 0) {
		a /= 5;
		b = 3 * a;
		c = 4 * a;
		cout << b << " " << c;
	} else if (a % 2 == 0) {
		a /= 2;
		m = (a + 1) / 2;
		n = (a - 1) / 2;
		b = 2 * 2 * m * n;
		c = 2 * (m * m + n * n);
		cout << b << " " << c;
	} else {
		m = (a + 1) / 2;
		n = (a - 1) / 2;
		b = 2 * m * n;
		c = m * m + n * n;
		cout << b << " " << c;
	}
}

int main(int argc, char* argv[]) {
	int n;

	cin >> n;

	solve(n);

	return 0;
}

/*
3
=====
4 5

6
=====
8 10

1
=====
-1

17
=====
144 145

67
=====
2244 2245
*/
