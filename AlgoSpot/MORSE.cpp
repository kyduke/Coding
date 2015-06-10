//https://algospot.com/judge/problem/read/MORSE

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

const int M = 1000000000 + 100;
int bino[201][201];
int skip;

void calcBino() {
	int i, j;

	memset(bino, 0, sizeof(bino));
	for (i = 0; i <= 200; i++) {
		bino[i][0] = bino[i][i] = 1;
		for (j = 1; j < i; j++) {
			bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);
		}
	}
}

void generate(int n, int m, string s) {
	if (skip < 0) return;

	if (n == 0 && m == 0) {
		if (skip == 0) cout << s << "\n";

		skip--;
		return;
	}

	if (bino[n + m][n] <= skip) {
		skip -= bino[n + m][n];
		return;
	}

	if (n > 0) generate(n - 1, m, s + "-");
	if (m > 0) generate(n, m - 1, s + "o");
}

int main(int argc, char* argv[]) {
	int C, n, m, k;

	calcBino();

	cin >> C;
	while (C--) {
		cin >> n >> m >> k;

		skip = k - 1;

		generate(n, m, "");
	}
	return 0;
}

/*
3
2 2 4
4 8 13
6 4 1
=====
o--o
--o-ooo-oooo
------oooo
*/
