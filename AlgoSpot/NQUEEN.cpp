// https://algospot.com/judge/problem/read/NQUEEN

#include <iostream>

typedef unsigned long long UINT64;

using namespace std;

UINT64 maskRow, maskDiagonal1, maskDiagonal2, count;

void solve(int n, int column) {
	int row, bitRow, bitDiagonal1, bitDiagonal2;

	if (column >= n) {
		count++;
		return;
	}

	for (row = 0; row < n; row++) {
		bitRow = 1 << row;
		bitDiagonal1 = 1 << (column + row);
		bitDiagonal2 = 1 << (n - column + row);
		if ((maskRow & bitRow) || (maskDiagonal1 & bitDiagonal1) || (maskDiagonal2 & bitDiagonal2)) continue;

		maskRow ^= bitRow;
		maskDiagonal1 ^= bitDiagonal1;
		maskDiagonal2 ^= bitDiagonal2;

		solve(n, column + 1);

		maskRow ^= bitRow;
		maskDiagonal1 ^= bitDiagonal1;
		maskDiagonal2 ^= bitDiagonal2;
	}
}

int main(int argc, char* argv[]) {
	int C, N;

	cin >> C;
	while (C--) {
		cin >> N;
		
		maskRow = 0;
		maskDiagonal1 = 0;
		maskDiagonal2 = 0;
		count = 0;
		solve(N, 0);

		cout << count << "\n";
	}

	return 0;
}

/*
3
1
2
8
=====
1
0
92
*/
