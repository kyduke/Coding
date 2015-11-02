// http://codeforces.com/problemset/problem/592/A

#include <iostream>

using namespace std;

const int SIZE = 8;

char board[SIZE][SIZE + 1];

void solve() {
	int i, j, a, b;

	a = 8;
	b = 8;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (board[j][i] == 'W') {
				a = min(a, j);
				break;
			} else if (board[j][i] == 'B') {
				break;
			}
		}

		for (j = SIZE - 1; j >= 0; j--) {
			if (board[j][i] == 'B') {
				b = min(b, SIZE - j - 1);
				break;
			} else if (board[j][i] == 'W') {
				break;
			}
		}
	}

	if (a <= b) {
		cout << "A\n";
	} else {
		cout << "B\n";
	}
}

int main(int argc, char* argv[]) {
	int i;

	i = 0;
	while (i < SIZE) {
		cin >> board[i];
		i++;
	}

	solve();

	return 0;
}


/*
........
........
.B....B.
....W...
........
..W.....
........
........
=====
A

..B.....
..W.....
......B.
........
.....W..
......B.
........
........
=====
B
*/
