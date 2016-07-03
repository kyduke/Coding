// LGE CodeJam 2016 Problem 4
// Failed Set3, Set4
// Lowest Common Ancestor 찾기 방식으로 풀림
// 부모를 1, 2, 4, 8, ... 로 저장하면 빨리 공통부모를 찾을 수 있음
// 1 ~ 500이면 250이 같은지 찾고, 다시 1~249나 250~500을 찾는 방식으로 공통부모를 찾음

#include <iostream>
#include <map>
#include <cstring>

using namespace std;

const int SIZE = 1000;

int m[SIZE][SIZE];
int w[SIZE][SIZE];
int z[SIZE];

void print2DArray(int n, int x[][SIZE]) {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << x[i][j] << " ";
		}
		cout << "\n";
	}
}

void dijkstra(int n, int x[][SIZE]) {
	int i, j, k, d;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j) continue;
			for (k = 0; k < n; k++) {
				if (i == k || j == k) continue;
				if (x[i][k] == 0 || x[j][k] == 0) continue;
				d = x[i][k] + x[j][k];
				if (x[i][j] == 0 || x[i][j] > d) {
					x[i][j] = d;
				}
			}
		}
	}
}

int main(int argc, char* argv[]) {
	int t, n, q, c, d, i, sumA, sumB;

	cin >> t;
	while (t--) {
		memset(m, 0, SIZE * SIZE * sizeof(int));
		memset(z, 0, SIZE * sizeof(int));

		cin >> n >> q;
		for (i = 1; i < n; i++) {
			cin >> c >> d;
			c--;
			z[i]++;
			z[c]++;
			m[i][c] = d;
			m[c][i] = d;
		}
		dijkstra(n, m);
		//print2DArray(n, m);
		memcpy(w, m, SIZE * SIZE * sizeof(int));
		for (i = 1; i < n; i++) {
			if (z[i] == 1) {
				cin >> d;
				if (w[0][i] > d) {
					w[0][i] = d;
					w[i][0] = d;
				}
			}
		}
		dijkstra(n, w);
		//print2DArray(n, w);
		sumA = 0;
		sumB = 0;
		while (q--) {
			cin >> c >> d;
			c--;
			d--;
			sumA += m[c][d];
			sumB += w[c][d];
		}
		cout << sumA << " " << sumB << "\n";
	}

	return 0;
}

/*
2
5 2
1 1
1 5
2 2
2 2
2
1
5
1 4
5 1
3 1
1 2
1 2
1
1
2 3
=====
6 4
4 2
*/
