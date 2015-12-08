// https://www.hackerrank.com/challenges/board-cutting

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long UINT64;

const UINT64 MOD = 1000000007;

UINT64 solve(vector<UINT64>& xs, vector<UINT64>& ys) {
	UINT64 cost;
	int i, j;

	sort(xs.begin(), xs.end(), greater<int>());
	sort(ys.begin(), ys.end(), greater<int>());

	cost = 0;
	
	i = 0;
	j = 0;
	while (i < xs.size() && j < ys.size()) {
		if (xs[i] > ys[j]) {
			cost = (cost + (j + 1) * xs[i]) % MOD;
			i++;
		} else {
			cost = (cost + (i + 1) * ys[j]) % MOD;
			j++;
		}
	}
	while (i < xs.size()) {
		cost = (cost + (j + 1) * xs[i]) % MOD;
		i++;
	}
	while (j < ys.size()) {
		cost = (cost + (i + 1) * ys[j]) % MOD;
		j++;
	}

	return cost;
}

int main(int argc, char* argv[]) {
	vector<UINT64> xs, ys;
	int t, n, m, i;

	cin >> t;
	while (t--) {
		cin >> n >> m;

		xs.assign(n - 1, 0);
		ys.assign(m - 1, 0);

		i = 0;
		while (i < n - 1) {
			cin >> xs[i];
			i++;
		}

		i = 0;
		while (i < m - 1) {
			cin >> ys[i];
			i++;
		}

		cout << solve(xs, ys) << "\n";
	}

	return 0;
}

/*
1
2 2
2
1
=====
4

1
6 4
2 1 3 1 4
4 1 2
=====
42
*/
