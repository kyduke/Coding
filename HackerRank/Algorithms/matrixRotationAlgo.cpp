// https://www.hackerrank.com/challenges/matrix-rotation-algo

#include <iostream>
#include <vector>

using namespace std;

int mat[300][300];

void printMatrix(int m, int n) {
	int i, j;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve(int m, int n, int r) {
	vector<int> shell;
	int i, j, k, s, maxShell;

	maxShell = m;
	if (m > n) maxShell = n;
	maxShell = (maxShell + 1) / 2;

	for (s = 0; s < maxShell; s++) {
		shell.clear();
		i = s;
		j = s;
		while (j < n - s - 1) {
			shell.push_back(mat[i][j]);
			j++;
		}
		while (i < m - s - 1) {
			shell.push_back(mat[i][j]);
			i++;
		}
		while (j > s) {
			shell.push_back(mat[i][j]);
			j--;
		}
		while (i > s) {
			shell.push_back(mat[i][j]);
			i--;
		}

		k = r % shell.size();
		for (i = 0; i < k; i++) {
			shell.push_back(shell[i]);
		}
		i = s;
		j = s;
		while (j < n - s - 1) {
			mat[i][j] = shell[k];
			k++;
			j++;
		}
		while (i < m - s - 1) {
			mat[i][j] = shell[k];
			k++;
			i++;
		}
		while (j > s) {
			mat[i][j] = shell[k];
			k++;
			j--;
		}
		while (i > s) {
			mat[i][j] = shell[k];
			k++;
			i--;
		}
	}
}

int main(int argc, char* argv[]) {
	int m, n, r, i, j;

	cin >> m >> n >> r;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	solve(m, n, r);
	printMatrix(m, n);

	return 0;
}

/*
4 4 1
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
=====
2 3 4 8
1 7 11 12
5 6 10 16
9 13 14 15

4 4 2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
=====
3 4 8 12
2 11 10 16
1 7 6 15
5 9 13 14

5 4 7
1 2 3 4
7 8 9 10
13 14 15 16
19 20 21 22
25 26 27 28
=====
28 27 26 25
22 9 15 19
16 8 21 13
10 14 20 7
4 3 2 1

2 2 3
1 1
1 1
=====
1 1
1 1
*/
