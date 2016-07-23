// http://codeforces.com/contest/699/problem/B

#include <iostream>
#include <map>

using namespace std;

const int SIZE = 1001;

char matrix[SIZE][SIZE];
int n, m;

void solve() {
	int i, j, x, y, count, count2;
	map<int, int> rows, cols;
	map<int, int>::iterator it;

	count = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (matrix[i][j] == '*') {
				x = i;
				y = j;
				it = rows.find(x);
				if (it == rows.end()) {
					rows.insert(make_pair(x, 1));
				} else {
					it->second++;
				}
				it = cols.find(y);
				if (it == cols.end()) {
					cols.insert(make_pair(y, 1));
				} else {
					it->second++;
				}
				count++;
			}
		}
	}

	if (count == 0) {
		cout << "YES\n";
		cout << 1 << " " << 1 << "\n";
		return;
	} else if (count == 1) {
		cout << "YES\n";
		cout << x + 1 << " " << y + 1 << "\n";
		return;
	}

	// row
	count2 = 0;
	for (i = 0; i < n; i++) {
		if (i == x) continue;
		for (j = 0; j < m; j++) {
			if (matrix[i][j] == '*') {
				count2++;
			}
		}
	}
	if (count2 == 0) {
		cout << "YES\n";
		cout << x + 1 << " " << 1 << "\n";
		return;
	}

	// column
	count2 = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (j == y) continue;
			if (matrix[i][j] == '*') {
				count2++;
			}
		}
	}
	if (count2 == 0) {
		cout << "YES\n";
		cout << 1 << " " << y + 1 << "\n";
		return;
	}

	if (count == 2) {
		x = -1;
		y = -1;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (matrix[i][j] == '*') {
					if (x == -1) {
						x = i;
					} else {
						y = j;
						cout << "YES\n";
						cout << x + 1 << " " << y + 1 << "\n";
						return;
					}
				}
			}
		}
	}

	x = -1;
	for (it = rows.begin(); it != rows.end(); it++) {
		if (it->second > 1) {
			if (x == -1) {
				x = it->first;
			} else {
				cout << "NO\n";
				return;
			}
		}
	}

	y = -1;
	for (it = cols.begin(); it != cols.end(); it++) {
		if (it->second > 1) {
			if (y == -1) {
				y = it->first;
			} else {
				cout << "NO\n";
				return;
			}
		}
	}

	if (x != -1 && y != -1) {
		for (i = 0; i < n; i++) {
			if (i == x) continue;
			for (j = 0; j < m; j++) {
				if (j == y) continue;
				if (matrix[i][j] == '*') {
					cout << "NO\n";
					return;
				}
			}
		}
		cout << "YES\n";
		cout << x + 1 << " " << y + 1 << "\n";
		return;
	} else if (x != -1) {
		y = -1;
		for (i = 0; i < n; i++) {
			if (i == x) continue;
			for (j = 0; j < m; j++) {
				if (matrix[i][j] == '*') {
					if (y = -1) {
						y = j;
					} else {
						cout << "NO\n";
						return;
					}
				}
			}
		}
		cout << "YES\n";
		cout << x + 1 << " " << y + 1 << "\n";
		return;
	} else if (y != -1) {
		x = -1;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (j == y) continue;
				if (matrix[i][j] == '*') {
					if (x == -1) {
						x = i;
					} else {
						cout << "NO\n";
						return;
					}
				}
			}
		}
		cout << "YES\n";
		cout << x + 1 << " " << y + 1 << "\n";
		return;
	}

	cout << "NO\n";
}

int main(int argc, char* argv[]) {
	int i;

	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> matrix[i];
	}

	solve();

	return 0;
}

/*
3 4
....
....
.*..
=====
YES
3 2

3 4
....
....
....
=====
YES
1 1

3 4
...*
....
.*..
=====
YES
1 2

3 4
**..
.*..
....
=====
YES
1 2

3 4
.*..
....
.*..
=====
YES
1 2

3 4
.*..
....
*.*.
=====
YES
1 2

3 4
..*.
...*
..*.
=====
YES
2 3

3 4
..*.
*..*
..*.
=====
YES
2 3

3 4
..*.
**.*
....
=====
YES
2 3

3 4
....
**.*
....
=====
YES
2 1

3 3
..*
.*.
*..
=====
NO

6 5
..*..
..*..
*****
..*..
..*..
..*..
=====
YES
3 3
*/
