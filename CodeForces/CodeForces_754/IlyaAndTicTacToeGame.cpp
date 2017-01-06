// http://codeforces.com/problemset/problem/754/B

#include <iostream>

using namespace std;

char grid[4][5];
char temp[8][9] = {0, };

bool win(int i, int j) {
	char xo;

	xo = temp[i][j];

	if (temp[i - 1][j - 1] == xo && temp[i + 1][j + 1] == xo) return true;
	if (temp[i - 1][j] == xo && temp[i + 1][j] == xo) return true;
	if (temp[i - 1][j + 1] == xo && temp[i + 1][j - 1] == xo) return true;
	if (temp[i][j - 1] == xo && temp[i][j + 1] == xo) return true;

	if (temp[i - 1][j - 1] == xo && temp[i - 2][j - 2] == xo) return true;
	if (temp[i - 1][j] == xo && temp[i - 2][j] == xo) return true;
	if (temp[i - 1][j + 1] == xo && temp[i - 2][j + 2] == xo) return true;
	if (temp[i][j + 1] == xo && temp[i][j + 2] == xo) return true;
	if (temp[i + 1][j + 1] == xo && temp[i + 2][j + 2] == xo) return true;
	if (temp[i + 1][j] == xo && temp[i + 2][j] == xo) return true;
	if (temp[i + 1][j - 1] == xo && temp[i + 2][j - 2] == xo) return true;
	if (temp[i][j - 1] == xo && temp[i][j - 2] == xo) return true;

	return false;
}

bool solve(int xo) {
	char x, o;
	int i, j;

	if (xo == 0) {
		x = 'x';
		o = 'o';
	} else {
		x = 'o';
		o = 'x';
	}

	for (i = 2; i < 6; i++) {
		for (j = 2; j < 6; j++) {
			if (temp[i][j] == '.') {
				temp[i][j] = x;
				if (win(i, j)) {
					temp[i][j] = '.';
					return true;
				}
				//single turn!!!
				/*
				if (solve((xo + 1) % 2) == false) {
					temp[i][j] = '.';
					return true;
				}
				*/
				temp[i][j] = '.';
			}
		}
	}

	return false;
}

int main(int argc, char* argv[]) {
	int i, j;

	for (i = 0; i < 4; i++) {
		cin >> grid[i];
	}

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			temp[i][j] = '.';
		}
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			temp[i + 2][j + 2] = grid[i][j];
		}
	}

	if (solve(0)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}

/*
xx..
.oo.
x...
oox.
=====
YES

x.ox
ox..
x.o.
oo.x
=====
NO

x..x
..oo
o...
x.xo
=====
YES

o.x.
o...
.x..
ooxx
=====
NO
*/
