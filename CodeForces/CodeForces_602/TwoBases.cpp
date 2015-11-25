// http://codeforces.com/contest/602/problem/A

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

int main(int argc, char* argv[]) {
	UINT64 x, y;
	int n, b, i;

	cin >> n >> b;
	x = 0;
	while (n--) {
		cin >> i;
		x = x * b + i;
	}

	cin >> n >> b;
	y = 0;
	while (n--) {
		cin >> i;
		y = y * b + i;
	}

	if (x > y) {
		cout << ">\n";
	} else if (x < y) {
		cout << "<\n";
	} else {
		cout << "=\n";
	}

	return 0;
}

/*
6 2
1 0 1 1 1 1
2 10
4 7
=====
=

3 3
1 0 2
2 5
2 4
=====
<

7 16
15 15 4 0 0 7 10
7 9
4 8 0 3 1 5 0
=====
>
*/
