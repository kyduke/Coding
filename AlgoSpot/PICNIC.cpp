// https://algospot.com/judge/problem/read/PICNIC

#include <iostream>
#include <string.h>

using namespace std;

int bud[10][10];
int visit[10];

int solve(int first, int prev, int n, int m) {
	int i, c;

	if (n == m) {
		return 1;
	}

	c = 0;
	if (m % 2 == 0) {
		for (i = first + 1; i < n; i++) {
			if (visit[i] == 0) {
				visit[i] = 1;
				c += solve(i, i, n, m + 1);
				visit[i] = 0;
			}
		}
	} else {
		for (i = prev + 1; i < n; i++) {
			if (visit[i] == 0 && bud[prev][i] == 1) {
				visit[i] = 1;
				c += solve(first, i, n, m + 1);
				visit[i] = 0;
			}
		}
	}

	return c;
}

int main(int argc, char* argv[]) {
	int C, n, m, a, b;

	cin >> C;
	while (C--) {
		memset(bud, 0, sizeof(int) * 10 * 10);
		memset(visit, 0, sizeof(int) * 10);

		cin >> n >> m;
		while (m--) {
			cin >> a >> b;
			if (a < b) {
				bud[a][b] = 1;
			} else {
				bud[b][a] = 1;
			}
		}

		cout << solve(-1, -1, n, 0) << "\n";
	}

	return 0;
}

/*
3 
2 1 
0 1 
4 6 
0 1 1 2 2 3 3 0 0 2 1 3 
6 10 
0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5
=====
1
3
4
*/
