// http://codeforces.com/problemset/problem/560/B

#include <iostream>

using namespace std;

int w, h, a1, b1, a2, b2;

bool solve() {
	int w1, h1, w2, h2;

	w1 = w - a1;
	h1 = h;

	w2 = w;
	h2 = h - b1;

	if (!((w1 == 0 && h2 == 0) || w1 < 0 || h2 < 0)) {
		if (w1 >= a2 && h1 >= b2) {
			return true;
		}
		if (w1 >= b2 && h1 >= a2) {
			return true;
		}
		if (w2 >= a2 && h2 >= b2) {
			return true;
		}
		if (w2 >= b2 && h2 >= a2) {
			return true;
		}
	}

	w1 = w - b1;
	h1 = h;

	w2 = w;
	h2 = h - a1;

	if (!((w1 == 0 && h2 == 0) || w1 < 0 || h2 < 0)) {
		if (w1 >= a2 && h1 >= b2) {
			return true;
		}
		if (w1 >= b2 && h1 >= a2) {
			return true;
		}
		if (w2 >= a2 && h2 >= b2) {
			return true;
		}
		if (w2 >= b2 && h2 >= a2) {
			return true;
		}
	}

	return false;
}

int main(int argc, char* argv[]) {

	cin >> w >> h >> a1 >> b1 >> a2 >> b2;

	if (solve() == true) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}

/*
3 2
1 3
2 1
=====
YES

5 5
3 3
3 3
=====
NO

4 2
2 3
1 2
=====
YES
*/
