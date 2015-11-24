// https://algospot.com/judge/problem/read/TRIPATHCNT

#include <iostream>
#include <string.h>

using namespace std;

typedef long long INT64;

const int SIZE = 100;

int tris[SIZE][SIZE];
INT64 sums[SIZE][SIZE];
int cnts[SIZE][SIZE];
int N;

INT64 solve(int depth, int pos) {
	INT64 sumA, sumB;

	if (depth == N - 1) {
		sums[depth][pos] = tris[depth][pos];
		cnts[depth][pos] = 1;
		return sums[depth][pos];
	}

	INT64& ret = sums[depth][pos];

	if (ret != -1) return ret;

	sumA = solve(depth + 1, pos) + tris[depth][pos];
	sumB = solve(depth + 1, pos + 1) + tris[depth][pos];

	if (sumA > sumB) {
		ret = sumA;
		cnts[depth][pos] = cnts[depth + 1][pos];
	} else if (sumA < sumB) {
		ret = sumB;
		cnts[depth][pos] = cnts[depth + 1][pos + 1];
	} else {
		ret = sumA;
		cnts[depth][pos] = cnts[depth + 1][pos] + cnts[depth + 1][pos + 1];
	}

	return ret;
}

int main(int argc, char* argv[]) {
	int T, i, j;

	cin >> T;
	while (T--) {
		memset(sums, -1, sizeof(INT64) * SIZE * SIZE);
		cin >> N;
		for (i = 0; i < N; i++) {
			for (j = 0; j <= i; j++) {
				cin >> tris[i][j];
			}
		}

		solve(0, 0);

		cout << cnts[0][0] << "\n";
	}

	return 0;
}

/*
2
4
1
1 1 
1 1 1 
1 1 1 1 
4
9
5 7
1 3 2
3 5 5 6
=====
8
3
*/
