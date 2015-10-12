// https://algospot.com/judge/problem/read/KAKURO2
// 시간초과

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int SIZE = 20;

int map[SIZE][SIZE];
int candis[SIZE][SIZE][2][10];
int sums[SIZE][SIZE][2];
int counts[SIZE][SIZE][2];
int starts[SIZE][SIZE][2];
vector<int> costs; // count of candis * 1000 + y * 20 + x
vector<int> cell[SIZE][SIZE];
int N;

bool findCandidate(int start, int y, int x, int d, int sum, int* cand) {
	bool ret;

	if (x >= N || y >= N) return false;
	if (sum < 0) return false;
	if (d == 0) {
		if (map[y][x] == 1 && (x == N - 1 || map[y][x + 1] == 0)) {
			if (sum < 10 && sum >= start) {
				cand[sum] = 1;
				return true;
			}
			return false;
		}

		ret = false;
		for (; start < 10; start++) {
			if (findCandidate(start + 1, y, x + 1, d, sum - start, cand) == true) {
				cand[start] = 1;
				ret = true;
			}
		}
	} else {
		if (map[y][x] == 1 && (y == N - 1 || map[y + 1][x] == 0)) {
			if (sum < 10 && sum >= start) {
				cand[sum] = 1;
				return true;
			}
			return false;
		}

		ret = false;
		for (; start < 10; start++) {
			if (findCandidate(start + 1, y + 1, x, d, sum - start, cand) == true) {
				cand[start] = 1;
				ret = true;
			}
		}
	}

	return ret;
}

void calcCost() {
	int cost, i, j, k, x, y;

	for (j = 0; j < N; j++) {
		for (i = 0; i < N; i++) {
			if (map[j][i] == 1) {
				cost = 0;
				y = starts[j][i][1];
				x = starts[j][i][0];
				for (k = 1; k < 10; k++) {
					if (candis[y][i][1][k] == 1 && candis[j][x][0][k] == 1) {
						cell[j][i].push_back(k);
						cost++;
					}
				}
				
				cost = cost * 1000 + j * SIZE + i;
				costs.push_back(cost);
			}
		}
	}

	sort(costs.begin(), costs.end());
}

bool fillCandidate(int start) {
	int i, j, k, x, y, n;

	if (start == costs.size()) return true;

	k = costs[start] % 1000;
	j = k / SIZE;
	i = k % SIZE;

	for (n = 0; n < cell[j][i].size(); n++) {
		k = cell[j][i][n];
		x = starts[j][i][0];
		if (candis[j][x][0][k] == 0) continue;
		if (counts[j][x][0] == 1 && sums[j][x][0] != k) continue;

		y = starts[j][i][1];
		if (candis[y][i][1][k] == 0) continue;
		if (counts[y][i][1] == 1 && sums[y][i][1] != k) continue;
			
		map[j][i] = k;
		candis[j][x][0][k] = 0;
		candis[y][i][1][k] = 0;
		sums[j][x][0] -= k;
		sums[y][i][1] -= k;
		counts[j][x][0]--;
		counts[y][i][1]--;
		if (fillCandidate(start + 1) == true) return true;
		map[j][i] = 1;
		candis[j][x][0][k] = 1;
		candis[y][i][1][k] = 1;
		sums[j][x][0] += k;
		sums[y][i][1] += k;
		counts[j][x][0]++;
		counts[y][i][1]++;
	}

	return false;
}

void solve() {
	int i, j;

	costs.clear();
	calcCost();
	fillCandidate(0);

	for (j = 0; j < N; j++) {
		for (i = 0; i < N; i++) {
			cout << map[j][i] << " ";
		}
		cout << "\n";
	}
}

int main(int argc, char* argv[]) {
	int T, Q, y, x, d, s, i, j;

	cin >> T;
	while (T--) {
		memset(candis, 0, sizeof(int) * SIZE * SIZE * 2 * 10);

		cin >> N;
		j = 0;
		while (j < N) {
			i = 0;
			while (i < N) {
				cin >> map[j][i];
				cell[j][i].clear();
				i++;
			}
			j++;
		}

		cin >> Q;
		while (Q--) {
			cin >> y >> x >> d >> s;
			sums[y - 1][x - 1][d] = s;
			if (d == 0) {
				findCandidate(1, y - 1, x, d, s, candis[y - 1][x - 1][d]);
				j = 0;
				for (i = x; i < N; i++) {
					if (map[y - 1][i] == 0) break;
					starts[y - 1][i][0] = x - 1;
					j++;
				}
				counts[y - 1][x - 1][0] = j;
			} else {
				findCandidate(1, y, x - 1, d, s, candis[y - 1][x - 1][d]);
				i = 0;
				for (j = y; j < N; j++) {
					if (map[j][x - 1] == 0) break;
					starts[j][x - 1][1] = y - 1;
					i++;
				}
				counts[y - 1][x - 1][1] = i;
			}
		}

		solve();
	}

	return 0;
}

/*
1
8
0 0 0 0 0 0 0 0
0 1 1 0 0 1 1 1
0 1 1 0 1 1 1 1
0 1 1 1 1 1 0 0
0 0 1 1 0 1 1 0
0 0 0 1 1 1 1 1
0 1 1 1 1 0 1 1
0 1 1 1 0 0 1 1
24
2 1 0 16
2 5 0 24
3 1 0 17
3 4 0 29
4 1 0 35
5 2 0 7
5 5 0 8
6 3 0 16
7 1 0 21
7 6 0 5
8 1 0 6
8 6 0 3
1 2 1 23
1 3 1 30
1 6 1 27
1 7 1 12
1 8 1 16
2 5 1 17
3 4 1 15
4 7 1 12
5 5 1 7
5 8 1 7
6 2 1 11
6 3 1 10
=====
0 0 0 0 0 0 0 0
0 9 7 0 0 8 7 9
0 8 9 0 8 9 5 7
0 6 8 5 9 7 0 0
0 0 6 1 0 2 6 0
0 0 0 4 6 1 3 2
0 8 9 3 1 0 1 4
0 3 1 2 0 0 2 1
*/
