// http://codeforces.com/contest/651/problem/A

#include <iostream>

using namespace std;

int solve(int a, int b) {
	int big, small, t, ret;

	ret = 0;
	big = a;
	small = b;
	while (big > 0 && small > 0) {
		if (big == 1 && small == 1) break;
		ret++;
		if (big < small) {
			t = big;
			big = small;
			small = t;
		}
		big -= 2;
		small++;
	}

	return ret;
}

int main(int argc, char* argv[]) {
	int a, b;

	cin >> a >> b;
	cout << solve(a, b) << "\n";

	return 0;
}

/*
3 5
=====
6

4 4
=====
5
*/
