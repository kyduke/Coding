// http://codeforces.com/contest/723/problem/A

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int a, b, c, d, e, i;

	cin >> a >> b >> c;

	e = 1000;
	for (i = 1; i <= 100; i++) {
		d = 0;
		if (a >= i) {
			d += a - i;
		} else {
			d += i - a;
		}
		if (b >= i) {
			d += b - i;
		} else {
			d += i - b;
		}
		if (c >= i) {
			d += c - i;
		} else {
			d += i - c;
		}
		e = min(e, d);
	}

	cout << e;

	return 0;
}

/*
7 1 4
=====
6

30 20 10
=====
20
*/
