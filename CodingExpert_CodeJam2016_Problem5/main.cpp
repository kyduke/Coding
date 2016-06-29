// LGE CodeJam 2016 Problem 5
// Failed set3, set4

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 1 << 17;

UINT64 cache[SIZE];
int powers[16];
int types[16];

UINT64 solve(vector<int>& v, unsigned int bit) {
	vector<int> c;
	UINT64 temp;
	int i, j, k, s, e;
	UINT64& ret = cache[bit];

	if (ret != -1) return ret;

	ret = 0;

	for (i = 0; i < v.size(); i++) {
		if (types[ v[i] ] == 1) continue;
		for (j = 0; j < v.size(); j++) {
			if (types[ v[j] ] == 0) continue;
			temp = powers[ v[i] ] * powers[ v[j] ];
			s = min(i, j);
			e = max(i, j);
			c.clear();
			bit = 0;
			for (k = s + 1; k < e; k++) {
				c.push_back(v[k]);
				bit |= 1 << (v[k] + 1);
			}
			temp += solve(c, bit);
			c.clear();
			bit = 0;
			for (k = 0; k < s; k++) {
				c.push_back(v[k]);
				bit |= 1 << (v[k] + 1);
			}
			for (k = e + 1; k < v.size(); k++) {
				c.push_back(v[k]);
				bit |= 1 << (v[k] + 1);
			}
			temp += solve(c, bit);
			ret = max(ret, temp);
		}
	}

	return ret;
}

int main(int argc, char* argv[]) {
	vector<int> v;
	int t, n, i;
	unsigned int bit;

	cin >> t;
	while (t--) {
		memset(cache, -1, SIZE * sizeof(int));
		cin >> n;
		v.clear();
		v.assign(n, 0);
		for (i = 0; i < n; i++) {
			cin >> powers[i];
		}
		for (i = 0; i < n; i++) {
			cin >> types[i];
		}
		bit = 0;
		for (i = 0; i < n; i++) {
			v[i] = i;
			bit |= 1 << (i + 1);
		}
		cout << solve(v, bit) << "\n";
	}

	return 0;
}

/*
1
4
1 8 2 9
1 0 1 0
=====
26
*/
