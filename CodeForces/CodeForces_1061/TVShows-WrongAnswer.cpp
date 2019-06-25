// https://codeforces.com/contest/1061/problem/D
// Wrong answer on test 43

#include <iostream>
#include <map>

using namespace std;

typedef long long INT64;

const INT64 MOD = 1000000007;
const int SIZE = 100000;

INT64 arr[SIZE][2];

int main() {
	multimap<INT64, INT64> left, right;
	multimap<INT64, INT64>::iterator it, jt;
	int n, i;
	INT64 k, x, y, l, r, ans, c1, c2, c3;
	
	cin >> n >> x >> y;
	for (i = 0; i < n; i++) {
		cin >> l >> r;
		arr[i][0] = l;
		arr[i][1] = r;
		left.insert(make_pair(l, i));
		right.insert(make_pair(r, i));
	}
	
	k = x / y;
	k++;
	
	for (it = right.begin(); it != right.end(); it++) {
		c1 = x + ((y * (arr[it->second][1] - arr[it->second][0])) % MOD);
		jt = left.upper_bound(it->first);
		while (jt != left.end()) {
			if (jt->first > it->first) {
				if ((jt->first - it->first) >= k) break;
				c2 = x + ((y * (arr[jt->second][1] - arr[jt->second][0])) % MOD);
				c3 = x + ((y * (arr[jt->second][1] - arr[it->second][0])) % MOD);
				if (c3 < c1 + c2) {
					arr[jt->second][0] = arr[it->second][0];
					arr[it->second][0] = 0;
					left.erase(jt);
					break;
				}
			}
			jt++;
		}
	}
	
	ans = 0;
	for (i = 0; i < n; i++) {
		if (arr[i][0] == 0) continue;
		ans = (ans + ((x + ((y * (arr[i][1] - arr[i][0])) % MOD)) % MOD)) % MOD;
	}
	cout << ans << "\n";
	
	return 0;
}

/*
5 4 3
1 2
4 10
2 4
10 11
5 9
=====
60

6 3 2
8 20
6 22
4 15
20 28
17 25
20 27
=====
142

2 1000000000 2
1 2
2 3
=====
999999997
*/
