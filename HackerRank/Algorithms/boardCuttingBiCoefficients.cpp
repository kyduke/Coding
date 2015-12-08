// https://www.hackerrank.com/challenges/board-cutting
// https://www.hackerrank.com/challenges/board-cutting/submissions/code/15645791
// failed big numbers

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long UINT64;

const UINT64 MOD = 1000000007;

UINT64 solve(vector<UINT64>& xs, vector<UINT64>& ys) {
	vector< vector<UINT64> > coe;
	vector<UINT64> v;
	UINT64 x, y;
	int i, j;
	
	sort(xs.begin(), xs.end(), greater<int>());
	sort(ys.begin(), ys.end(), greater<int>());


	v.assign(xs.size() + 1, 0);
	coe.assign(ys.size() + 1, v);
	
	for (i = 0; i < xs.size(); i++) {
		coe[0][i + 1] = coe[0][i] + xs[i];
	}
	for (j = 0; j < ys.size(); j++) {
		coe[j + 1][0] = coe[j][0] + ys[j];
	}

	for (j = 0; j < ys.size(); j++) {
		for (i = 0; i < xs.size(); i++) {
			x = (coe[j][i + 1] + ((i + 2) * ys[j])) % MOD;
			y = (coe[j + 1][i] + ((j + 2) * xs[i])) % MOD;
			if (x < y) {
				coe[j + 1][i + 1] = x;
			} else {
				coe[j + 1][i + 1] = y;
			}
		}
	}

	return coe[ys.size()][xs.size()];
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
