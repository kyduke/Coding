//http://codeforces.com/problemset/problem/548/B

#include <iostream>

using namespace std;

int row = -1;
int lastCount = 0;

int findMaxConsecutiveAll(int grid[501][501], int n, int m) {
	int i, j, temp, count;

	count = 0;
	for (i = 0; i < n; i++) {
		temp = 0;
		for (j = 0; j < m; j++) {
			if (grid[i][j] == 1) {
				temp++;
			} else if (temp > 0) {
				if (count < temp) {
					count = temp;
					row = i;
				}
				temp = 0;
			}
		}
		if (count < temp) {
			count = temp;
			row = i;
		}
	}

	lastCount = count;

	return count;
}

int findMaxConsecutiveRow(int grid[501][501], int n, int m, int i) {
	int j, temp, count;

	count = lastCount;
	temp = 0;
	for (j = 0; j < m; j++) {
		if (grid[i][j] == 1) {
			temp++;
		} else if (temp > 0) {
			if (count < temp) {
				count = temp;
				row = i;
			}
			temp = 0;
		}
	}
	if (count < temp) {
		count = temp;
		row = i;
	}

	lastCount = count;

	return count;
}

int main(int argc, char *argv[]) {
	int n, m, q, i, j;
	int grid[501][501];

	cin >> n >> m >> q;
	
	i = 0;
	while (i < n) {
		j = 0;
		while (j < m) {
			cin >> grid[i][j];
			j++;
		}
		i++;
	}

	while (q--) {
		cin >> i >> j;
		grid[i - 1][j - 1] = (grid[i - 1][j - 1] + 1) % 2;
		if (row == -1 || row == i - 1) {
			cout << findMaxConsecutiveAll(grid, n, m) << "\n";
		} else {
			cout << findMaxConsecutiveRow(grid, n, m, i - 1) << "\n";
		}
	}

	return 0;
}
