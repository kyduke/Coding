// http://codeforces.com/problemset/problem/553/A

#include <iostream>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 1001;

int binom[MAXN][MAXN];

void fillBinomial() {
	int i, j;

	binom[0][0] = 1;
	for (i = 1; i < MAXN; i++) {
		binom[i][0] = 1;
		for (j = 1; j <= i; j++) {
			binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
		}
	}
}

int main(int argc, char* argv[]) {
	int k, n, total;
	long long result;

	fillBinomial();

	result = 1;
	total = 0;
	cin >> k;
	while (k--) {
		cin >> n;
		result = (result * binom[total + n - 1][n - 1]) % MOD;
		total += n;
	}

	cout << result << "\n";

	return 0;
}

/*
3
2
2
1
=====
3

4
1
2
3
4
=====
1680
*/
