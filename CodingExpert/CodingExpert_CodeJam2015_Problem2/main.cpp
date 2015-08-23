//LGE CodeJam 2015 Problem2
//채점은 실패함

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

multiset<int> walls;
int N, K, W;

bool solve() {
	multiset<int>::iterator it, upper;
	int i;

	i = 0;
	for (it = walls.begin(); it != walls.end(); it++) {
		if (i > K) break;

		upper = walls.upper_bound(*it + W);
		if (upper == walls.end()) return true;

		upper = walls.upper_bound(*upper + W);
		if (upper == walls.end()) return true;

		if (distance(it, upper) + K >= walls.size()) return true;
		
		i++;
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
				walls.insert(y);
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
				walls.insert(y);
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