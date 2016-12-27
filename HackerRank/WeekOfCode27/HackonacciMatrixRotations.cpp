// https://www.hackerrank.com/contests/w27/challenges/hackonacci-matrix-rotations

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

UINT64 d1, d2;

void solve(int n) {
	UINT64 i, j, a, b;
	int v[7] = {1, 1, 0, 1, 0, 0, 1};

	d1 = 0;
	d2 = 0;

	n++;
	for (i = 1; i < n; i++) {
		for (j = 1; j < n; j++) {
			a = ((j * i) * (j * i)) % 7;
			b = (((n - i) * j) * ((n - i) * j)) % 7;
			if (v[a] != v[b]) d1++;
			b = (((n - i) * (n - j)) * ((n - i) * (n - j))) % 7;
			if (v[a] != v[b]) d2++;
		}
	}
}

int main(int argc, char* argv[]) {
	int n, q, a;

	cin >> n;

	solve(n);

	cin >> q;
	while (q--) {
		cin >> a;
		a %= 360;
		if (a == 0) {
			cout << "0\n";
		} else if (a == 180) {
			cout << d2 << "\n";
		} else {
			cout << d1 << "\n";
		}
	}

	return 0;
}

/*
4 3
90
180
270
=====
10
6
10
*/
