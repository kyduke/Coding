// https://www.hackerrank.com/contests/101hack40/challenges/next-topological-sorting
// 18 pass of 30
// 12 timeout

#include <iostream>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

const int SIZE = 100001;

int visit[SIZE] = {0, };
int p[SIZE];
int q[SIZE];
vector<int> parents[SIZE * 2];
int n, m;

set<int> candidates;

int usable(int a) {
	int i;

	for (i = 0; i < parents[a].size(); i++) {
		if (visit[ parents[a][i] ] == 1) return 0;
	}

	return 1;
}

bool fill(int i, int c) {
	set<int>::iterator it;
	int k;

	if (usable(c) == 0) return false;

	q[i] = c;
	visit[c] = 0;

	if (i == n - 1) return true;

	for (it = candidates.begin(); it != candidates.end(); it++) {
		if (visit[*it] == 0) continue;
		if (fill(i + 1, *it) == true) return true;
	}

	visit[c] = 1;

	return false;
}

void solve() {
	set<int>::iterator it;
	int i, j;

	visit[ p[n - 1] ] = 1;
	visit[ p[n - 2] ] = 1;
	candidates.insert(p[n - 1]);
	candidates.insert(p[n - 2]);
	i = n - 2;
	while (i >= 0) {
		for (it = candidates.lower_bound(p[i] + 1); it != candidates.end(); it++) {
			if (fill(i, *it) == true) {
				for (j = 0; j < n; j++) {
					cout << q[j] << " ";
				}
				return;
			}
		}
		i--;
		visit[ p[i] ] = 1;
		candidates.insert(p[i]);
	}

	cout << -1;
}

int main(int argc, char* argv[]) {
	int i, u, v;

	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> u >> v;
		parents[v].push_back(u);
	}

	for (i = 0; i < n; i++) {
		cin >> p[i];
		q[i] = p[i];
	}

	if (n == 1) {
		cout << -1;
	} else {
		solve();
	}

	return 0;
}

/*
5 5
1 3
2 3
3 4
2 5
5 4
1 2 5 3 4
=====
2 1 3 5 4

1 0
1
=====
-1

2 1
1 2
1 2
=====
-1

2 0
1 2
=====
2 1
*/
