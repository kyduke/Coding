// http://codeforces.com/contest/629/problem/A

#include <iostream>

using namespace std;

const int SIZE = 100;

int solve(char map[SIZE][SIZE + 1], int n) {
	char cnt[SIZE] = {0, };
	int i, j, k, ret;

	ret = 0;
	for (i = 0; i < n; i++) {
		k = 0;
		for (j = 0; j < n; j++) {
			if (map[i][j] == 'C') {
				cnt[j]++;
				k++;
			}
		}
		ret += k * (k - 1);
	}

	for (i = 0; i < n; i++) {
		ret += cnt[i] * (cnt[i] - 1);
	}

	return ret / 2;
}

int main(int argc, char* argv[]) {
	int n, i;
	char map[SIZE][SIZE + 1];

	cin >> n;
	i = 0;
	while (i < n) {
		cin >> map[i];
		i++;
	}

	cout << solve(map, n) << "\n";

	return 0;
}

/*
3
.CC
C..
C.C
=====
4

4
CC..
C..C
.CC.
.CC.
=====
9
*/
