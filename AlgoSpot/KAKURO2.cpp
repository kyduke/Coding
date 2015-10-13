// https://algospot.com/judge/problem/read/KAKURO2

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int SIZE = 20;

int masks[10][46];
int map[SIZE][SIZE];
int maskMap[SIZE][SIZE];
int hints[SIZE][SIZE][2][3];
int starts[SIZE][SIZE][2];
vector<int> costs; // count of candis * 1000 + y * 20 + x
vector<int> cells[SIZE][SIZE];
int N;

void getCount(int n, int* sum, int* count) {
	int i;

	*count = 0;
	*sum = 0;
	i = 1;
	while (i < 10) {
		if (n & (1 << i)) {
			(*count)++;
			*sum += i;
		}
		i++;
	}
}

void fillMasks() {
	int i, sum, count;

	memset(masks, 0, sizeof(int) * 10 * 46);

	sum = 0;
	count = 0;
	for (i = 2; i < 1024; i += 2) {
		getCount(i, &sum, &count);
		masks[count][sum] |= i;
	}
}

void fillCandiMask(int y, int x, int d, int sum) {
	int i, count, mask;

	count = 0;
	if (d == 0) {
		for (i = x + 1; i < N; i++) {
			if (map[y][i] == 0) break;
			count++;
		}
		mask = masks[count][sum];
		for (i = x + 1; i < N; i++) {
			if (map[y][i] == 0) break;
			maskMap[y][i] = mask;
			starts[y][i][0] = x;
		}
	} else {
		for (i = y + 1; i < N; i++) {
			if (map[i][x] == 0) break;
			count++;
		}
		mask = masks[count][sum];
		for (i = y + 1; i < N; i++) {
			if (map[i][x] == 0) break;
			maskMap[i][x] &= mask;
			starts[i][x][1] = y;
		}
	}
	hints[y][x][d][0] = mask;
	hints[y][x][d][1] = count;
	hints[y][x][d][2] = sum;
}

void findCandidate() {
	int i, j, k, sum, count;

	costs.clear();

	for (j = 0; j < N; j++) {
		for (i = 0; i < N; i++) {
			if (map[j][i] == 0) continue;
			getCount(maskMap[j][i], &sum, &count);
			costs.push_back(count * 1000 + j * 20 + i);
			cells[j][i].clear();
			for (k = 1; k < 10; k++) {
				if ((maskMap[j][i] & (1 << k))) cells[j][i].push_back(k);
			}
		}
	}

	sort(costs.begin(), costs.end());
}

bool fillCandidate(int start) {
	int i, j, k, bit, n, x, y, maskH, maskV, countH, countV, sumH, sumV;
	
	if (start == costs.size()) return true;

	k = costs[start] % 1000;
	j = k / SIZE;
	i = k % SIZE;
	x = starts[j][i][0];
	y = starts[j][i][1];
	maskH = hints[j][x][0][0];
	maskV = hints[y][i][1][0];
	countH = hints[j][x][0][1];
	countV = hints[y][i][1][1];
	sumH = hints[j][x][0][2];
	sumV = hints[y][i][1][2];

	for (k = 0; k < cells[j][i].size(); k++) {
		n = cells[j][i][k];
		bit = 1 << n;

		if ((maskH & bit) == 0) continue;
		if (countH == 1 && sumH != n) continue;
		
		if ((maskV & bit) == 0) continue;
		if (countV == 1 && sumV != n) continue;

		map[j][i] = n;
		hints[j][x][0][0] ^= bit;
		hints[y][i][1][0] ^= bit;
		hints[j][x][0][1]--;
		hints[y][i][1][1]--;
		hints[j][x][0][2] -= n;
		hints[y][i][1][2] -= n;
		if (fillCandidate(start + 1) == true) return true;
		hints[y][i][1][2] += n;
		hints[j][x][0][2] += n;
		hints[y][i][1][1]++;
		hints[j][x][0][1]++;
		hints[y][i][1][0] ^= bit;
		hints[j][x][0][0] ^= bit;
		map[j][i] = 1;
	}

	return false;
}

void solve() {
	int i, j;

	findCandidate();
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

	fillMasks();

	cin >> T;
	while (T--) {
		cin >> N;
		j = 0;
		while (j < N) {
			i = 0;
			while (i < N) {
				cin >> map[j][i];
				maskMap[j][i] = 0;
				i++;
			}
			j++;
		}

		cin >> Q;
		while (Q--) {
			cin >> y >> x >> d >> s;
			fillCandiMask(y - 1, x - 1, d, s);
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
