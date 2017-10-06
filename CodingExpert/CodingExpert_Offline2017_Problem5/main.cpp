// LG Code Jam 2017 final E

#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef unsigned int UINT32;

const int SIZE = 500001;
const int STEP = 2000;

// Small size test
// const int SIZE = 501;
// const int STEP = 2;

UINT32 data[SIZE][2] = {0, };
map<UINT32, UINT32> cache[SIZE / STEP + 1];

void buildCache(UINT32 n) {
	map<UINT32, UINT32> m;
	map<UINT32, UINT32>::iterator it;
	UINT32 i, j, e, bit;

	for (i = 0; i <= SIZE / STEP; i++) {
		cache[i].clear();
	}

	cache[0][0] = 0;
	i = 0;
	j = 0;
	e = 0;
	while (e < n) {
		m.clear();
		e = min(i + STEP, n);
		while (i < e) {
			i++;
			m[ data[i][0] ] = data[i][1];
		}
		j++;
		cache[j] = cache[j - 1];
		for (it = m.begin(); it != m.end(); it++) {
			cache[j][it->first] = it->second;
		}
	}

	for (i = 1; i <= j; i++) {
		bit = 0;
		for (it = cache[i].begin(); it != cache[i].end(); it++) {
			bit ^= it->second;
			it->second = bit;
		}
	}
}

UINT32 solve(UINT32 s, UINT32 a, UINT32 b) {
	map<UINT32, UINT32> m;
	map<UINT32, UINT32>::iterator it, jt;
	UINT32 ans, i, j;

	ans = 0;

	j = (s - 1) / STEP;
	it = cache[j].lower_bound(a);
	if (it == cache[j].end()) it--;
	while (it->first >= a) {
		it--;
	}
	jt = cache[j].lower_bound(b);
	if (jt == cache[j].end()) jt--;
	while (jt->first > b) {
		jt--;
	}
	ans = it->second;
	if (it != jt) {
		ans ^= jt->second;
	}

	for (i = j * STEP + 1; i <= s; i++) {
		if (data[i][0] < a || data[i][0] > b) continue;
		m[ data[i][0] ] = data[i][1];
	}

	for (it = m.begin(); it != m.end(); it++) {
		ans ^= it->second;
		jt = cache[j].find(it->first);
		if (jt != cache[j].end()) {
			ans ^= jt->second;
			if (jt != cache[j].begin()) {
				jt--;
				ans ^= jt->second;
			}
		}
	}

	return ans;
}

int main(int argc, char* argv[]) {
	UINT32 t, n, c, q, s, a, b, i, x;

	cin >> t;
	while (t--) {
		cin >> n >> c >> q;
		for (i = 1; i <= c; i++) {
			cin >> data[i][0] >> data[i][1];
		}
		buildCache(c);

		x = 0;
		for (i = 0; i < q; i++) {
			cin >> s >> a >> b;
			s ^= x;
			a ^= x;
			b ^= x;
			x = solve(s, a, b);
		}
		cout << x << "\n";
	}

	return 0;
}

/*
3
2 3 3
2 5
1 4
1 3
3 1 2
7 7 7
2 1 2
3 3 3
1 5
2 8
3 9
3 1 3
6 7 7
1 1 2
4 2 2
2 1
3 4
1 1 2
0 0 0
=====
1
5
0

1
3 3 1
1 1
2 2
2 3
3 1 2
=====
2

1
3 3 1
1 1
2 2
2 3
3 2 2
=====
3
*/
