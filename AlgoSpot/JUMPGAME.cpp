// https://algospot.com/judge/problem/read/JUMPGAME

#include <iostream>
#include <string.h>

using namespace std;

int map[100][100];
int cache[100][100];

int canJump(int x, int y, int n) {
	int& ret = cache[y][x];
	int c;

	if (x == n - 1 && y == n - 1) {
		ret = 1;
		return ret;
	}

	if (ret != -1) {
		return ret;
	}

	ret = 0;
	c = map[y][x];

	if (x + c < n) {
		ret |= canJump(x + c, y, n);
	}
	if (y + c < n) {
		ret |= canJump(x, y + c, n);
	}

	return ret;
}

int main(int argc, char* argv[]) {
	int C, n, x, y;

	cin >> C;
	while (C--) {
		cin >> n;
		for (y = 0; y < n; y++) {
			for (x = 0; x < n; x++) {
				cin >> map[y][x];
			}
		}

		memset(cache, -1, sizeof(int) * 100 * 100);
		if (canJump(0, 0, n) > 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}

/*
2
7
2 5 1 6 1 4 1
6 1 1 2 2 9 3
7 2 3 2 1 3 1
1 1 3 1 7 1 2
4 1 2 3 4 1 2
3 3 1 2 3 4 1
1 5 2 9 4 7 0
7
2 5 1 6 1 4 1
6 1 1 2 2 9 3
7 2 3 2 1 3 1
1 1 3 1 7 1 2
4 1 2 3 4 1 3
3 3 1 2 3 4 1
1 5 2 9 4 7 0 
=====
YES
NO
*/
