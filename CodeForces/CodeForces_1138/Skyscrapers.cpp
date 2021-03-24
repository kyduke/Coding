// http://codeforces.com/contest/1138/problem/C

#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

const int SIZE = 1001;

int board[SIZE][SIZE] = { 0, };
int rows[SIZE][SIZE] = { 0, };
int cols[SIZE][SIZE] = { 0, };
int maxes[2][SIZE] = { 0, };

int main(int argc, char** argv) {
	map<int, int> mm;
	map<int, int>::iterator it;
	int n, m, i, j, k;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	for (i = 0; i < n; i++) {
		mm.clear();
		for (j = 0; j < m; j++) {
			mm.insert(make_pair(board[i][j], 0));
		}
		j = 1;
		for (it = mm.begin(); it != mm.end(); it++) {
			it->second = j;
			j++;
		}
		maxes[0][i] = j - 1;
		for (j = 0; j < m; j++) {
			it = mm.find(board[i][j]);
			rows[i][j] = it->second;
		}
	}

	for (j = 0; j < m; j++) {
		mm.clear();
		for (i = 0; i < n; i++) {
			mm.insert(make_pair(board[i][j], 0));
		}
		i = 1;
		for (it = mm.begin(); it != mm.end(); it++) {
			it->second = i;
			i++;
		}
		maxes[1][j] = i - 1;
		for (i = 0; i < n; i++) {
			it = mm.find(board[i][j]);
			cols[i][j] = it->second;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (rows[i][j] == cols[i][j]) {
				k = max(maxes[0][i], maxes[1][j]);
			}
			else if (rows[i][j] < cols[i][j]) {
				k = max(maxes[0][i] + cols[i][j] - rows[i][j], maxes[1][j]);
			}
			else {
				k = max(maxes[0][i], maxes[1][j] + rows[i][j] - cols[i][j]);
			}
			printf("%d ", k);
		}
		printf("\n");
	}

	return 0;
}

/*
2 3
1 2 1
2 1 2
=====
2 2 2
2 2 2

2 2
1 2
3 4
=====
2 3
3 2
*/
