// https://algospot.com/judge/problem/read/MMRECT1

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, vector<int>> points;
int N;

bool findPoint(int y, int x1, int x2) {
	map<int, vector<int>>::iterator it;

	it = points.find(y);
	if (it != points.end()) {
		if (find(it->second.begin(), it->second.end(), x1) == it->second.end()) return false;
		if (find(it->second.begin(), it->second.end(), x2) == it->second.end()) return false;
		return true;
	}

	return false;
}

void solve() {
	int i, j, k, w, y;
	int minWidth, maxWidth;
	map<int, vector<int>>::iterator it;
	vector<int> v;

	minWidth = 1000000000;
	maxWidth = 0;
	for (it = points.begin(); it != points.end(); it++) {
		y = it->first;
		v = it->second;
		k = v.size();
		if (k < 2) continue;
		sort(v.begin(), v.end());
		for (i = 0; i < k - 1; i++) {
			for (j = i + 1; j < k; j++) {
				w = v[j] - v[i];
				if (w >= minWidth && w <= maxWidth) {
					continue;
				}
				if (findPoint(y + w, v[i], v[j]) == true) {
					minWidth = min(minWidth, w);
					maxWidth = max(maxWidth, w);
				}
			}
		}
	}

	cout << minWidth << " " << maxWidth << "\n";
}

int main(int argc, char* argv[]) {
	int T, i, x, y;
	map<int, vector<int>>::iterator it;

	cin >> T;
	while (T--) {
		cin >> N;
		points.clear();
		i = 0;
		while (i < N) {
			cin >> x >> y;
			it = points.find(y);
			if (it == points.end()) {
				vector<int> v;
				v.push_back(x);
				points.insert(pair<int, vector<int>>(y, v));
			} else {
				it->second.push_back(x);
			}
			i++;
		}
		solve();
	}

	return 0;
}

/*
2
4
0 0
2 2
2 0
0 2
10
0 0
2 2
2 0
0 2
-10 -10
7 7
10 10
-10 10
10 -10
5 8
=====
2 2
2 20
*/
