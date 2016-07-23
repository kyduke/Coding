// http://codeforces.com/contest/699/problem/C

#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 100;

int acts[SIZE];
int cache[3][SIZE];
int n;

int solve(int idx, int prev) {
	if (idx >= n) return 0;

	int& ret = cache[prev][idx];

	if (ret != -1) return ret;

	if (acts[idx] == 0) {
		ret = solve(idx + 1, 0) + 1;
	} else if (acts[idx] == 1) {
		if (prev != 1) {
			ret = solve(idx + 1, 1);
		} else {
			ret = solve(idx + 1, 0) + 1;
		}
	} else if (acts[idx] == 2) {
		if (prev != 2) {
			ret = solve(idx + 1, 2);
		} else {
			ret = solve(idx + 1, 0) + 1;
		}
	} else {
		if (prev == 0) {
			ret = solve(idx + 1, 1);
			ret = min(ret, solve(idx + 1, 2));
		} else if (prev == 1) {
			ret = solve(idx + 1, 2);
		} else {
			ret = solve(idx + 1, 1);
		}
	}

	return ret;
}

int main(int argc, char* argv[]) {
	int i, a;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> acts[i];
	}

	memset(cache, -1, sizeof(int) * 3 * SIZE);
	cout << solve(0, 0) << "\n";

	return 0;
}

/*
4
1 3 2 0
=====
2

7
1 3 3 2 1 2 3
=====
0

2
2 2
=====
1
*/
