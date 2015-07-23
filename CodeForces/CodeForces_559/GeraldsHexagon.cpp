// http://codeforces.com/problemset/problem/559/A

#include <iostream>

using namespace std;

int a, b, c, d, e, f;

int solve() {
	int count;

	count = (a + f + b) * (a + f + b);
	count -= f * f;
	count -= b * b;
	count -= d * d;

	return count;
}

int main(int argc, char* argv[]) {
	cin >> a >> b >> c >> d >> e >> f;

	cout << solve() << "\n";

	return 0;
}

/*
1 1 1 1 1 1
=====
6

1 2 1 2 1 2
=====
13
*/
