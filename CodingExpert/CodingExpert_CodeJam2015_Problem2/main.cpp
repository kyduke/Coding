//LGE CodeJam 2015 Problem2
//라지만 성공함

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> walls;
int N, K, W;

bool solve() {
	int i, j, k, limit, lastY, minX, maxX;
	bool failed;

	sort(walls.begin(), walls.end());

	for (i = 0; i <= K; i++) {
		minX = 2000000001;
		maxX = -2000000001;
		for (j = 0; j < N - K; j++) {
			minX = min(minX, walls[i + j].second);
			maxX = max(maxX, walls[i + j].second);
		}

		limit = walls[i].first + W;
		for (j = 0; j < N - K; j++) {
			if (walls[i + j].first > limit) break;
		}

		limit = walls[i + N - K - 1].first - W;
		for (k = N - K - 1; k >= 0; k--) {
			if (walls[i + k].first < limit) break;
		}

		failed = false;
		for (; j <= k; j++) {
			if (walls[i + j].second < minX || walls[i + j].second > maxX) {
				failed = true;
				break;
			} else if (walls[i + j].second > minX + W && walls[i + j].second < maxX - W) {
				failed = true;
				break;
			}
		}

		if (failed == false) return true;
	}

	return false;
}

int main(int argc, char* argv[]) {
	ifstream dataFile;
	int T;
	int n;
	int x, y;

	if (argc > 1) {
		dataFile.open(argv[1]);
		dataFile >> T;
		while (T--) {
			dataFile >> N >> K >> W;

			walls.clear();
			n = N;
			while (n--) {
				dataFile >> x >> y;
				walls.push_back(make_pair(y, x));
			}

			if (solve() == true) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
		dataFile.close();
	} else {
		cin >> T;
		while (T--) {
			cin >> N >> K >> W;

			walls.clear();
			n = N;
			while (n--) {
				cin >> x >> y;
				walls.push_back(make_pair(y, x));
			}

			if (solve() == true) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}

/*
2
7 1 1
1 1
1 5
3 2
3 4
3 7
5 1
5 5
7 0 1
1 1
1 5
3 2
3 4
3 7
5 1
5 5
=====
YES
NO
*/
