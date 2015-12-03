// https://www.hackerrank.com/challenges/dijkstrashortreach

#include <iostream>
#include <string.h>

using namespace std;

const int SIZE = 3000;

int maps[SIZE][SIZE];

void dijkstra(int start, int n) {
	int i, j, k, dist, temp;
	bool update;

	update = true;
	while (update) {
		update = false;
		i = start;
		for (j = 0; j < n; j++) {
			if (i == j) continue;
			dist = maps[i][j];
			for (k = 0; k < n; k++) {
				if (maps[i][k] == -1 || maps[k][j] == -1) continue;
				temp = maps[i][k] + maps[k][j];
				if (dist == -1 || dist > temp) {
					dist = temp;
					update = true;
				}
			}
			maps[i][j] = dist;
			maps[j][i] = dist;
		}
	}
}

int main(int argc, char* argv[]) {
	int t, n, m, x, y, r, s;

	cin >> t;
	while (t--) {
		memset(maps, -1, sizeof(int) * SIZE * SIZE);

		cin >> n >> m;

		while (m--) {
			cin >> x >> y >> r;
			x--;
			y--;
			if (maps[x][y] == -1 || maps[x][y] > r) {
				maps[x][y] = r;
				maps[y][x] = r;
			}
		}

		cin >> s;
		s--;

		dijkstra(s, n);

		for (m = 0; m < n; m++) {
			if (m == s) continue;
			cout << maps[s][m] << " ";
		}
		cout << "\n";
	}

	return 0;
}

/*
1
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1
=====
24 3 15
*/
