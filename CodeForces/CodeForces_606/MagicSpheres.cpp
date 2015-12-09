// http://codeforces.com/contest/606/problem/A

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	int a, b, c, x, y, z;

	cin >> a >> b >> c;
	cin >> x >> y >> z;

	x = a - x;
	if (x > 0) x /= 2;

	y = b - y;
	if (y > 0) y /= 2;

	z = c - z;
	if (z > 0) z /= 2;

	if (x + y + z >= 0) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	return 0;
}

/*
4 4 0
2 1 2
=====
Yes

5 6 1
2 7 2
=====
No

3 3 3
2 2 2
=====
Yes
*/
