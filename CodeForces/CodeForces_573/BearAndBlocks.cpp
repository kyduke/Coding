// http://codeforces.com/problemset/problem/573/B

#include <iostream>

using namespace std;

int blocks[100000];
int shells[100000];
int n;

int solve() {
	int i, maxShell;

	shells[0] = 1;
	for (i = 1; i < n; i++) {
		shells[i] = min(shells[i - 1] + 1, min(blocks[i], blocks[i - 1] + 1));
	}

	shells[n - 1] = 1;
	maxShell = 1;
	for (i = n - 2; i >= 0; i--) {
		shells[i] = min(shells[i], min(shells[i + 1] + 1, min(blocks[i], blocks[i + 1] + 1)));
		maxShell = max(maxShell, shells[i]);
	}

	return maxShell;
}

int main(int argc, char* argv[]) {
	int i;

	cin >> n;

	i = 0;
	while (i < n) {
		cin >> blocks[i++];
	}

	cout << solve() << "\n";

	return 0;
}

/*
6
2 1 4 6 2 2
=====
3

7
3 3 3 1 3 3 3
=====
2
*/
