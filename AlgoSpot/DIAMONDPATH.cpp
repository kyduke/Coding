// https://algospot.com/judge/problem/read/DIAMONDPATH

#include <iostream>
#include <string.h>

using namespace std;

const int SIZE = 100;

int map[SIZE][SIZE];
int cache[SIZE][SIZE];
int N;

int getBiggestPathSum(int x, int y) {
	if (x >= N || y >= N) return 0;
	if (x == N - 1 && y == N - 1) return map[y][x];

	int& ret = cache[y][x];

	if (ret != -1) return ret;

	ret = max(getBiggestPathSum(x + 1, y), getBiggestPathSum(x, y + 1)) + map[y][x];

	return ret;
}

int main(int argc, char* argv[]) {
	int C, i, j;

	cin >> C;
	while (C--) {
		cin >> N;
		memset(cache, -1, sizeof(int) * SIZE * SIZE);
		i = 0;
		while (i < N) {
			j = 0;
			while (j <= i) {
				cin >> map[i - j][j];
				j++;
			}
			i++;
		}
		while (i < 2 * N) {
			j = i - N + 1;
			while (j < N) {
				cin >> map[i - j][j];
				j++;
			}
			i++;
		}

		cout << getBiggestPathSum(0, 0) << "\n";
	}

	return 0;
}

/*
2
5
6
1 2
6 7 4
9 4 1 7
6 7 5 9 4
4 4 3 2
1 2 3
6 1
7
5
39
43 16
74 94 24
25 76 98 62
79 58 71 67 98
43 55 27 44
10 96 56
73 31
95
=====
48
664
*/
