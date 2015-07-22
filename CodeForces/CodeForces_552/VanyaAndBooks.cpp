// http://codeforces.com/problemset/problem/552/B

#include <iostream>

using namespace std;

unsigned long long countDigits(int n) {
	unsigned long long c, a, b, d;

	c = 0;
	a = 10;
	b = 9;
	d = 1;
	while (n >= a) {
		c += b * d;
		a *= 10;
		b *= 10;
		d++;
	}
	a /= 10;
	c += d * (n - a + 1);

	return c;
}

int main(int argc, char* argv[]) {
	int n;

	cin >> n;

	cout << countDigits(n) << "\n";

	return 0;
}

/*
13
=====
17

4
=====
4
*/
