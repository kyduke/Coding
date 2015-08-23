//LGE CodeJam 2015 Problem2
//채점은 실패함

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

multimap<int, int> walls;
int N, K, W;

bool solve() {
	multimap<int, int>::iterator it, wall;
	int i, j, limit, minX, maxX;
	bool minChanged, maxChanged;

	it = walls.begin();

	i = 0;
	while (i <= K) {
		limit = it->first + W;
		wall = it;
		minX = 2000000001;
		maxX = -2000000001;
		while (wall != walls.end()) {
			if (wall->first > limit) {
				break;
			}
			minX = min(minX, wall->second);
			maxX = max(maxX, wall->second);
			wall++;
		}

		minChanged = false;
		maxChanged = false;

		while (wall != walls.end()) {
			if (wall->second < minX) {
				if (minChanged == false) {
					minChanged = true;
					minX = wall->second;
				} else {
					break;
				}
			} else if (wall->second > maxX) {
				if (maxChanged == false) {
					maxChanged = true;
					maxX = wall->second;
				} else {
					break;
				}
			} else if (wall->second > minX && wall->second < maxX) {
				break;
			}

			wall++;
		}

		limit = wall->first + W;
		wall++;
		while (wall != walls.end()) {
			if (wall->second < minX || wall->second > maxX) {
				break;
			}
			if (wall->first > limit) {
				break;
			}
			wall++;
		}

		j = distance(wall, walls.end());

		if (i + j <= K) return true;

		i++;
		it++;
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
				walls.insert(make_pair(y, x));
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
				walls.insert(make_pair(y, x));
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
