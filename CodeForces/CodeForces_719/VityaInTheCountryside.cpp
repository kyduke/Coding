// http://codeforces.com/problemset/problem/719/A

#include <iostream>

using namespace std;

void solve(int a, int b) {
	if (a == 15) {
		cout << "DOWN";
		return;
	}

	if (a == 0) {
		cout << "UP";
		return;
	}

	if (b < 0) {
		cout << "-1";
		return;
	}

	if (a > b) {
		cout << "UP";
	} else {
		cout << "DOWN";
	}
}

int main(int argc, char* argv[]) {
	int n, a, b;

	a = -1;
	b = -1;

	cin >> n;
	while (n--) {
		b = a;
		cin >> a;
	}

	solve(a, b);

	return 0;
}

/*
5
3 4 5 6 7
=====
UP

7
12 13 14 15 14 13 12
=====
DOWN

1
8
=====
-1
*/
