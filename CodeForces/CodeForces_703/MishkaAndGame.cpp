// http://codeforces.com/contest/703/problem/A

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int n, a, b, m, c;

	m = 0;
	c = 0;

	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (a > b) {
			m++;
		} else if (a < b) {
			c++;
		}
	}

	if (m > c) {
		cout << "Mishka";
	} else if (m < c) {
		cout << "Chris";
	} else {
		cout << "Friendship is magic!^^";
	}

	return 0;
}

/*
3
3 5
2 1
4 2
=====
Mishka

2
6 1
1 6
=====
Friendship is magic!^^

3
1 5
3 3
2 2
=====
Chris
*/
