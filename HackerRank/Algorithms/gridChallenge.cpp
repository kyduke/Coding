// https://www.hackerrank.com/challenges/grid-challenge

#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 100;

char grid[SIZE][SIZE];

int main(int argc, char* argv[]) {
	int t, n, i, j;
	bool sorted;

	cin >> t;
	while (t--) {
		cin >> n;
		i = 0;
		while (i < n) {
			cin >> grid[i];
			sort(grid[i], grid[i] + n);
			i++;
		}
		
		sorted = true;
		for (i = 0; i < n - 1; i++) {
			for (j = 0; j < n; j++) {
				if (grid[i][j] > grid[i + 1][j]) {
					sorted = false;
					break;
				}
			}
		}

		if (sorted) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}

/*
1
5
ebacd
fghij
olmkn
trpqs
xywuv
=====
YES
*/
