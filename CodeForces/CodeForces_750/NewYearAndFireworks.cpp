// CodeForces Good Bye 2016 D
// http://codeforces.com/contest/750/problem/D

#include <iostream>
#include <set>

using namespace std;

const int SIZE = 400;

int m[SIZE][SIZE] = {0, };
int arr[31] = {0, };
int n;

void moveNext(int x, int y, int d, int z, set<int>& s) {
	int i;

	if (d == 0) {
		for (i = 0; i < z; i++) {
			y++;
			m[y][x] = 1;
		}
	} else if (d == 1) {
		for (i = 0; i < z; i++) {
			x++;
			y++;
			m[y][x] = 1;
		}
	} else if (d == 2) {
		for (i = 0; i < z; i++) {
			x++;
			m[y][x] = 1;
		}
	} else if (d == 3) {
		for (i = 0; i < z; i++) {
			x++;
			y--;
			m[y][x] = 1;
		}
	} else if (d == 4) {
		for (i = 0; i < z; i++) {
			y--;
			m[y][x] = 1;
		}
	} else if (d == 5) {
		for (i = 0; i < z; i++) {
			x--;
			y--;
			m[y][x] = 1;
		}
	} else if (d == 6) {
		for (i = 0; i < z; i++) {
			x--;
			m[y][x] = 1;
		}
	} else if (d == 7) {
		for (i = 0; i < z; i++) {
			x--;
			y++;
			m[y][x] = 1;
		}
	}
	s.insert(x + y * 1000 + ((d + 7) % 8) * 1000000);
	s.insert(x + y * 1000 + ((d + 1) % 8) * 1000000);
}

int solve() {
	set<int> s1, s2;
	set<int>::iterator it;
	int i, x, y, d, ans;

	x = 200;
	y = 200;
	d = 0;
	s1.insert(x + y * 1000 + d * 1000000);

	for (i = 0; i < n; i++) {
		if (i % 2 == 0) {
			s2.clear();
			for (it = s1.begin(); it != s1.end(); it++) {
				d = *it;
				x = d % 1000;
				d /= 1000;
				y = d % 1000;
				d /= 1000;
				moveNext(x, y, d, arr[i], s2);
			}
		} else {
			s1.clear();
			for (it = s2.begin(); it != s2.end(); it++) {
				d = *it;
				x = d % 1000;
				d /= 1000;
				y = d % 1000;
				d /= 1000;
				moveNext(x, y, d, arr[i], s1);
			}
		}
	}

	ans = 0;
	for (x = 0; x < SIZE; x++) {
		for (y = 0; y < SIZE; y++) {
			ans += m[y][x];
		}
	}

	return ans;
}

int main(int argc, char* argv[]) {
	int i;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << solve() << "\n";

	return 0;
}

/*
4
4 2 2 3
=====
39

6
1 1 1 1 1 3
=====
85

1
3
=====
3
*/
