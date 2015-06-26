// https://algospot.com/judge/problem/read/GRIDISLANDS

#include <iostream>

using namespace std;

const int MOD = 20090711;

int binom[5103][2551];

void makeBinom(int n, int r) {
	int i, j;

	for (i = 0; i <= n; i++) {
		for (j = 0; j < min(i, r); j++) {
			if (j == 0 || j == i) {
				binom[i][j] = 1;
			} else {
				binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
			}
		}
	}
}

void solve(int n) {
	int bridges, i, l, c;

	bridges = n * n + (n + 1) * (n + 1);

	l = bridges / 2;

	c = 1;
	for (i = 1; i <= l; i++) {
		c = (c + binom[bridges + 1][i]) % MOD;
	}

	cout << c << "\n";
}

int main() {
	int C, N;

	makeBinom(5102, 2551);

	cin >> C;
	while (C--) {
		cin >> N;
		solve(N);
	}

	return 0;
}

/*
3
1
4
30
=====
16
7286879
349268
*/
