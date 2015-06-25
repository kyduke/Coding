// http://codeforces.com/problemset/problem/554/B

#include <iostream>

using namespace std;

void solve(char (&grid)[100][101], int n) {
	int i, j, k, result, temp, cnt;

	result = 0;
	for (i = 0; i < n; i++) {
		if (grid[i][0] == 2) continue;
		temp = 1;
		for (j = i + 1; j < n; j++) {
			cnt = 0;
			for (k = 0; k < n; k++) {
				if (grid[i][k] != grid[j][k]) {
					cnt = -1;
					break;
				}
			}
			if (cnt == 0) {
				grid[j][0] = 2;
				temp++;
			}
		}
		result = max(result, temp);
	}

	cout << result << "\n";
}

int main(int argc, char* argv[]) {
	char grid[100][101];
	int n, i;

	cin >> n;
	i = 0;
	while (i < n) {
		cin >> grid[i];
		i++;
	}

	solve(grid, n);

	return 0;
}

/*
4
0101
1000
1111
0101
=====
2

3
111
111
111
=====
3
*/
