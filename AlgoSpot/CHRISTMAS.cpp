// https://algospot.com/judge/problem/read/CHRISTMAS

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long UINT64;

const int MOD = 20091101;

vector<int> sums;

int casesOfSingleOrder(int k) {
	vector<UINT64> counts;
	int ret, i;

	counts.assign(k, 0);

	for (i = 0; i < sums.size(); i++) {
		counts[ sums[i] ]++;
	}

	ret = 0;

	for (i = 0; i < k; i++) {
		if (counts[i] < 2) continue;
		ret = (ret + counts[i] * (counts[i] - 1) / 2) % MOD;
	}

	return ret;
}

int casesOfMultipleOrder(int k) {
	vector<int> cache;
	vector<int> pos;
	int i, p;

	cache.assign(sums.size(), 0);

	pos.assign(k, -1);
	pos[0] = 0;

	for (i = 1; i < sums.size(); i++) {
		cache[i] = cache[i - 1];
		p = pos[ sums[i] ];
		if (p != -1) {
			cache[i] = max(cache[i], cache[p] + 1);
		}
		pos[ sums[i] ] = i;
	}

	return cache.back();
}

int main(int argc, char* argv[]) {
	int t, n, k, i, p;

	cin >> t;
	while (t--) {
		cin >> n >> k;
		
		sums.clear();
		sums.assign(n + 1, 0);
		i = 1;
		while (i <= n) {
			cin >> p;
			sums[i] = (sums[i - 1] + p) % k;
			i++;
		}
		cout << casesOfSingleOrder(k) << " ";
		cout << casesOfMultipleOrder(k) << "\n";
	}

	return 0;
}

/*
2
6 4
1 2 3 4 5 6
4 1
1 2 3 4
=====
3 1
10 4
*/
