// https://algospot.com/judge/problem/read/CLOCKSYNC

#include <iostream>

using namespace std;

int grid[16];
int switches[10][16];
int sum;

void initSwitches() {
	switches[0][0] = 1;
	switches[0][1] = 1;
	switches[0][2] = 1;

	switches[1][3] = 1;
	switches[1][7] = 1;
	switches[1][9] = 1;
	switches[1][11] = 1;

	switches[2][4] = 1;
	switches[2][10] = 1;
	switches[2][14] = 1;
	switches[2][15] = 1;

	switches[3][0] = 1;
	switches[3][4] = 1;
	switches[3][5] = 1;
	switches[3][6] = 1;
	switches[3][7] = 1;

	switches[4][6] = 1;
	switches[4][7] = 1;
	switches[4][8] = 1;
	switches[4][10] = 1;
	switches[4][12] = 1;

	switches[5][0] = 1;
	switches[5][2] = 1;
	switches[5][14] = 1;
	switches[5][15] = 1;

	switches[6][3] = 1;
	switches[6][14] = 1;
	switches[6][15] = 1;

	switches[7][4] = 1;
	switches[7][5] = 1;
	switches[7][7] = 1;
	switches[7][14] = 1;
	switches[7][15] = 1;

	switches[8][1] = 1;
	switches[8][2] = 1;
	switches[8][3] = 1;
	switches[8][4] = 1;
	switches[8][5] = 1;
	
	switches[9][3] = 1;
	switches[9][4] = 1;
	switches[9][5] = 1;
	switches[9][9] = 1;
	switches[9][13] = 1;
}

void makeSum() {
	int i;

	sum = 0;
	for (i = 0; i < 16; i++) {
		sum += grid[i];
	}
}

int solve(int start, int count) {
	int i, j, c;

	if (start == 10) {
		return -1;
	}
	
	for (i = 0; i < 4; i++) {
		makeSum();
		c = count + i;
		if (sum == 0) {
			return c;
		}
		c = solve(start + 1, c);
		if (sum == 0) {
			return c;
		}
		for (j = 0; j < 16; j++) {
			if (switches[start][j] == 1) {
				grid[j] = (grid[j] + 3) % 4;
			}
		}
	}

	return -1;
}

int main(int argc, char* argv[]) {
	int C, i, t;

	initSwitches();
	
	cin >> C;
	while (C--) {
		for (i = 0; i < 16; i++) {
			cin >> t;
			grid[i] = (12 - t) / 3;
		}
		cout << solve(0, 0) << "\n";
	}

	return 0;
}

/*
2
12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12 
12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6
=====
2
9
*/
