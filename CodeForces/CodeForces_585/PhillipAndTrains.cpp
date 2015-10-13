// http://codeforces.com/problemset/problem/585/B

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 100;

int cells[3][SIZE + 1];
int n, x, y;

void parseCells(char* buffer, int row) {
	int i;
	
	for (i = 0; i < n; i++) {
		if (buffer[i] == 's' || buffer[i] == '.') {
			cells[row][i] = 0;
			if (buffer[i] == 's') {
				x = i;
				y = row;
			}
		} else {
			cells[row][i] = 1;
		}
	}

	cells[row][n] = 2;
	for (i = n - 1; i >= 0; i--) {
		if (cells[row][i] == 1) break;
		cells[row][i] = 2;
	}
}

bool solve() {
	vector<pair<int, int>> curr, prev;
	int i, j, r, c;

	prev.push_back(make_pair(x, y));
	i = 0;
	while (i <= n) {
		i += 3;
		curr = prev;
		prev.clear();
		if (curr.size() == 0) break;
		for (j = 0; j < curr.size(); j++) {
			c = curr[j].first;
			r = curr[j].second;

			//one step right
			c++;
			if (cells[r][c] == 1) {
				continue;
			}
				
			if (cells[r][c] == 2) {
				return true;
			}

			//two step right
			if (cells[r][c + 1] == 2) {
				return true;
			} else if (cells[r][c + 1] == 0) {
				if (cells[r][c + 2] == 2) {
					return true;
				} else if (cells[r][c + 2] == 0) {
					cells[r][c + 2] = 1;
					prev.push_back(make_pair(c + 2, r));
				}
			}

			//move up
			if (r > 0) {
				if (cells[r - 1][c] == 2) {
					return true;
				} else if (cells[r - 1][c] == 0) {
					//two step right
					if (cells[r - 1][c + 1] == 2) {
						return true;
					} else if (cells[r - 1][c + 1] == 0) {
						if (cells[r - 1][c + 2] == 2) {
							return true;
						} else if (cells[r - 1][c + 2] == 0) {
							cells[r - 1][c + 2] = 1;
							prev.push_back(make_pair(c + 2, r - 1));
						}
					}
				}
			}

			//move down
			if (r < 2) {
				if (cells[r + 1][c] == 2) {
					return true;
				} else if (cells[r + 1][c] == 0) {
					//two step right
					if (cells[r + 1][c + 1] == 2) {
						return true;
					} else if (cells[r + 1][c + 1] == 0) {
						if (cells[r + 1][c + 2] == 2) {
							return true;
						} else if (cells[r + 1][c + 2] == 0) {
							cells[r + 1][c + 2] = 1;
							prev.push_back(make_pair(c + 2, r + 1));
						}
					}
				}
			}
		}
	}

	return false;
}

int main(int argc, char* argv[]) {
	int t, k;
	char buffer[101];

	cin >> t;
	while (t--) {
		cin >> n >> k;

		for (k = 0; k < 3; k++) {
			cin >> buffer;
			parseCells(buffer, k);
		}

		if (solve()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}

/*
4
16 4
...AAAAA........
s.BBB......CCCCC
........DDDDD...
16 4
...AAAAA........
s.BBB....CCCCC..
.......DDDDD....
10 4
s.ZZ......
.....AAABB
.YYYYYY...
10 4
s.ZZ......
....AAAABB
.YYYYYY...
=====
YES
NO
YES
NO
*/
