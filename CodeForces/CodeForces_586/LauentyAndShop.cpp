// http://codeforces.com/contest/586/problem/B

#include <iostream>

using namespace std;

const int SIZE = 50;
const int MAX_DIST = 100000;

int row[2][SIZE];
int cross[SIZE];
int n;

int solve() {
	int minA, minB, i, dist;

	minA = MAX_DIST;
	minB = MAX_DIST;

	for (i = 0; i < n; i++) {
		dist = row[0][i] + cross[i] + row[1][n - 1] - row[1][i];
		if (dist < minA) {
			minB = minA;
			minA = dist;
		} else if (dist < minB) {
			minB = dist;
		}
	}

	return minA + minB;
}

int main(int argc, char* argv[]) {
	int a, i;

	cin >> n;
	i = 1;
	row[0][0] = 0;
	while (i < n) {
		cin >> a;
		row[0][i] = row[0][i - 1] + a;
		i++;
	}
	i = 1;
	row[1][0] = 0;
	while (i < n) {
		cin >> a;
		row[1][i] = row[1][i - 1] + a;
		i++;
	}
	i = 0;
	while (i < n) {
		cin >> cross[i];
		i++;
	}

	cout << solve() << "\n";

	return 0;
}

/*
4
1 2 3
3 2 1
3 2 2 3
=====
12

3
1 2
3 3
2 1 3
=====
11

2
1
1
1 1
=====
4
*/
