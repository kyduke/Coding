// https://algospot.com/judge/problem/read/BLOCKGAME

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> blocks;
char cache[33554432];

void preCalc() {
	int i, j, k;

	for (i = 0; i < 4; i++) {
		for (j = 4; j < 5; j++) {
			k = i * 5 + j;
			blocks.push_back((1 << k) | (1 << (k + 5)));
		}
	}

	for (i = 4; i < 5; i++) {
		for (j = 0; j < 4; j++) {
			k = i * 5 + j;
			blocks.push_back((1 << k) | (1 << (k + 1)));
		}
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			k = i * 5 + j;
			blocks.push_back((1 << k) | (1 << (k + 1)));
			blocks.push_back((1 << k) | (1 << (k + 5)));
			blocks.push_back((1 << k) | (1 << (k + 1)) | (1 << (k + 5)));
			blocks.push_back((1 << k) | (1 << (k + 1)) | (1 << (k + 6)));
			blocks.push_back((1 << k) | (1 << (k + 5)) | (1 << (k + 6)));
			blocks.push_back((1 << (k + 1)) | (1 << (k + 5)) | (1 << (k + 6)));
		}
	}
}

char play(int n) {
	char& ret = cache[n];
	int i;

	if (ret != -1) return ret;

	ret = 0;
	for (i = 0; i < blocks.size(); i++) {
		if (n & blocks[i]) continue;
		if (play(n | blocks[i]) == 0) {
			ret = 1;
			break;
		}
	}

	return ret;
}

int main(int argc, char* argv[]) {
	int C, i, j, n;
	char buffer[8];

	memset(cache, -1, sizeof(char) * 33554432);
	preCalc();

	cin >> C;
	while (C--) {
		n = 0;
		for (i = 0; i < 5; i++) {
			cin >> buffer;
			for (j = 0; j < 5; j++) {
				if (buffer[j] != '#') continue;
				n += 1 << (i * 5 + j);
			}
		}
		if (play(n) == 1) {
			cout << "WINNING\n";
		} else {
			cout << "LOSING\n";
		}
	}

	return 0;
}

/*
3
.....
.##..
##..#
#.###
..#..
.....
.....
.....
.....
.....
#..##
##.##
##.##
#...#
##.##
=====
WINNING
LOSING
WINNING
*/
