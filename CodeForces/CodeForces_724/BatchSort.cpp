// http://codeforces.com/problemset/problem/724/B

#include <iostream>

using namespace std;

const int SIZE = 32;

int n, m;

int arr[SIZE][SIZE];

bool sorted() {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (arr[i][j] != j) return false;
		}
	}

	return true;
}

void swapColumn(int a, int b) {
	int i, temp;
	
	for (i = 0; i < n; i++) {
		temp = arr[i][a];
		arr[i][a] = arr[i][b];
		arr[i][b] = temp;
	}
}

int diffCount(int r) {
	int cnt, i;

	cnt = 0;

	for (i = 0; i < m; i++) {
		if (arr[r][i] != i) cnt++;
	}

	return cnt;
}

bool solve() {
	int i, j, k, c, r;

	if (sorted() == true) return true;

	r = 0;
	for (k = 0; k < n; k++) {
		c = diffCount(k);
		if (c != 0 && c != 2) {
			r = -1;
			break;
		}
	}
	if (r == 0) return true;

	for (i = 0; i < m; i++) {
		for (j = i + 1; j < m; j++) {
			swapColumn(i, j);
			if (sorted() == true) return true;
			r = 0;
			for (k = 0; k < n; k++) {
				c = diffCount(k);
				if (c != 0 && c != 2) {
					r = -1;
					break;
				}
			}
			if (r == 0) return true;
			swapColumn(j, i);
		}
	}

	return false;
}

int main(int argc, char* argv[]) {
	int i, j;

	cin >> n >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> arr[i][j];
			arr[i][j]--;
		}
	}

	if (solve() == true) {
		cout << "YES";
	} else {
		cout << "NO";
	}


	return 0;
}

/*
2 4
1 3 2 4
1 3 4 2
=====
YES

4 4
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
=====
NO

3 6
2 1 3 4 5 6
1 2 4 3 5 6
1 2 3 4 6 5
=====
YES
*/
