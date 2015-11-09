// http://codeforces.com/contest/595/problem/B

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 100000;
const int DIVIDE = 1000000007;

UINT64 a[SIZE];
UINT64 b[SIZE];
int n, k;

int solve() {
	int i, last;
	UINT64 c, ret;

	last = 1;
	i = 0;
	while (i < k) {
		last *= 10;
		i++;
	}

	ret = 1;
	for (i = 0; i < n; i++) {
		c = (UINT64)(last - 1) / a[i] + 1;
		if (k == 1) {
			if (b[i] % a[i] == 0 || b[i] == 0) c--;
		} else {
			c -= (UINT64)((b[i] + 1) * last * 0.1 - 1) / a[i];
			if (b[i] == 0) {
				c--;
			} else {
				c += (UINT64)(b[i] * last * 0.1 - 1) / a[i];
			}
		}
		ret = (ret * c) % DIVIDE;
	}

	return ret;
}

int main(int argc, char* argv[]) {
	int i;

	cin >> n >> k;
	n = n / k;

	i = 0;
	while (i < n) {
		cin >> a[i];
		i++;
	}

	i = 0;
	while (i < n) {
		cin >> b[i];
		i++;
	}

	cout << solve() << "\n";

	return 0;
}

/*
6 2
38 56 49
7 3 4
=====
8

8 2
1 22 3 44
5 4 3 2
=====
32400
*/
