// https://www.hackerrank.com/contests/101hack32/challenges/tree-construction

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int>& degrees) {
	vector<pair<int, int>> d;
	vector<int> parents;
	int i, j, k, m, n;

	n = degrees.size();
	parents.assign(n, -1);

	for (i = 0; i < n; i++) {
		d.push_back(make_pair(degrees[i], i));
	}

	sort(d.begin(), d.end(), greater<pair<int, int>>());

	for (i = 0; i < n; i++) {
		k = d[i].second;
		if (degrees[k] == 0) continue;
		for (j = 0; j < n; j++) {
			m = d[j].second;
			if (k == m) continue;
			if (parents[m] != -1) continue;
			if (degrees[m] == 0) continue;
			parents[m] = k;
			degrees[k]--;
			degrees[m]--;
			if (degrees[k] == 0) break;
		}
	}

	for (i = 0; i < n; i++) {
		cout << (parents[i] + 1) << "\n";
	}
}

int main(int argc, char* argv[]) {
	vector<int> degrees;
	int n, i;

	cin >> n;

	degrees.assign(n, 0);

	i = 0;
	while (i < n) {
		cin >> degrees[i];
		i++;
	}

	solve(degrees);

	return 0;
}

/*
5
3 2 1 1 1
=====
2
0
2
1
1
*/
