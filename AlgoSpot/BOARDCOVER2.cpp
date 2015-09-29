// https://algospot.com/judge/problem/read/BOARDCOVER2

#include <iostream>

using namespace std;

struct Block {
	int w;
	int h;
	int board[10];
};

int board[10];
Block blocks[4];
int maskG = (1 << 10) - 1;
int W, H, countSpace, countBlockCell, minBlockW, minBlockH;
int maxBlocks;

void printBoard() {
	int i, j;

	for (j = 0; j < H; j++) {
		for (i = 0; i < 10; i++) {
			if (board[j] & (1 << (10 - 1 - i))) {
				cout << "#";
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}
}

int row2mask(char buffer[18], bool fillTen) {
	int i, mask;

	mask = 0;
	i = 0;
	while (buffer[i] != '\0') {
		mask = mask << 1;
		if (buffer[i] == '#') {
			mask++;
		} else if (fillTen) {
			countSpace++;
		}
		i++;
	}
	if (fillTen) {
		while (i < 10) {
			mask = (mask << 1) + 1;
			i++;
		}
	}

	return mask;
}

void preCalculateBlocks(char buffer[10][16], int R, int C) {
	int i, j, k, count;
	char temp[16];

	//remove first empty row
	while (true) {
		count = 0;
		for (i = 0; i < C; i++) {
			if (buffer[0][i] == '#') {
				count = 1;
				break;
			}
		}

		if (count != 0) break;

		for (j = 0; j < R - 1; j++) {
			for (i = 0; i < C; i++) {
				buffer[j][i] = buffer[j + 1][i];
			}
		}
		R--;
	}

	//remove last empty row
	while (true) {
		count = 0;
		for (i = 0; i < C; i++) {
			if (buffer[R - 1][i] == '#') {
				count = 1;
				break;
			}
		}

		if (count != 0) break;

		R--;
	}

	//remove left empty column
	while (true) {
		count = 0;
		for (j = 0; j < R; j++) {
			if (buffer[j][0] == '#') {
				count = 1;
				break;
			}
		}

		if (count != 0) break;

		for (j = 0; j < R; j++) {
			for (i = 0; i < C - 1; i++) {
				buffer[j][i] = buffer[j][i + 1];
			}
		}
		C--;
	}

	//remove right empty column
	while (true) {
		count = 0;
		for (j = 0; j < R; j++) {
			if (buffer[j][C - 1] == '#') {
				count = 1;
				break;
			}
		}

		if (count != 0) break;

		C--;
	}

	//countBlockCell
	countBlockCell = 0;
	for (j = 0; j < R; j++) {
		for (i = 0; i < C; i++) {
			if (buffer[j][i] == '#') countBlockCell++;
		}
	}

	//rotate 0
	blocks[0].w = C;
	blocks[0].h = R;
	for (j = 0; j < R; j++) {
		blocks[0].board[j] = row2mask(buffer[j], false);
	}

	//rotate 180
	blocks[1].w = C;
	blocks[1].h = R;
	for (j = R - 1; j >= 0; j--) {
		for (i = C - 1; i >= 0; i--) {
			temp[C - 1 - i] = buffer[j][i];
		}
		temp[C] = '\0';
		blocks[1].board[R - 1 - j] = row2mask(temp, false);
	}

	//rotate 90
	blocks[2].w = R;
	blocks[2].h = C;
	for (i = C - 1; i >= 0; i--) {
		for (j = 0; j < R; j++) {
			temp[j] = buffer[j][i];
		}
		temp[R] = '\0';
		blocks[2].board[C - 1 - i] = row2mask(temp, false);
	}

	//rotate 270
	blocks[3].w = R;
	blocks[3].h = C;
	for (i = 0; i < C; i++) {
		for (j = R - 1; j >= 0; j--) {
			temp[R - 1 - j] = buffer[j][i];
		}
		temp[R] = '\0';
		blocks[3].board[i] = row2mask(temp, false);
	}

	minBlockW = 10;
	minBlockH = 10;

	//remove duplcate block
	for (i = 0; i < 3; i++) {
		if (blocks[i].w == 0 || blocks[i].h == 0) continue;
		minBlockW = min(minBlockW, blocks[i].w);
		minBlockH = min(minBlockH, blocks[i].h);
		count = 0;
		for (j = i + 1; j < 4; j++) {
			if (blocks[i].w == blocks[j].w && blocks[i].h == blocks[j].h) {
				for (k = 0; k < R; k++) {
					if (blocks[i].board[k] != blocks[j].board[k]) {
						count = 1;
						break;
					}
				}
				if (count == 0) {
					blocks[j].w = 0;
					blocks[j].h = 0;
				}
			}
		}
	}
}

int countSpaces(int x, int y) {
	int i, j, count;

	count = 0;
	for (i = x; i < 10; i++) {
		if ((board[y] & (1 << (10 - 1 - i))) == 0) count++;
	}
	for (j = y + 1; j < H; j++) {
		for (i = 0; i < 10; i++) {
			if ((board[j] & (1 << (10 - 1 - i))) == 0) count++;
		}
	}

	return count;
}

int solve(int x, int y, int blockCount) {
	int i, j, mask, count, space;
	bool setable;

	space = countSpaces(x, y);

	count = blockCount;
	if (space < countBlockCell) {
		maxBlocks = max(maxBlocks, count);
		return maxBlocks;
	}
	if (count + (space / countBlockCell) <= maxBlocks) return maxBlocks;

	if (x + minBlockW > W) {
		x = 0;
		y++;
	}
	if (y + minBlockH > H) {
		maxBlocks = max(maxBlocks, count);
		return maxBlocks;
	}

	for (i = 0; i < 4; i++) {
		if (blocks[i].w == 0 || blocks[i].h == 0) continue;
		if (x + blocks[i].w > W || y + blocks[i].h > H) continue;
		setable = true;
		for (j = 0; j < blocks[i].h; j++) {
			mask = blocks[i].board[j] << (10 - blocks[i].w - x);
			if (board[y + j] & mask) {
				setable = false;
				break;
			}
		}
		if (setable == false) continue;

		for (j = 0; j < blocks[i].h; j++) {
			mask = blocks[i].board[j] << (10 - blocks[i].w - x);
			board[y + j] = board[y + j] | mask;
		}

		count = max(count, solve(x + 1, y, blockCount + 1));

		for (j = 0; j < blocks[i].h; j++) {
			mask = blocks[i].board[j] << (10 - blocks[i].w - x);
			board[y + j] &= maskG ^ mask;
		}
	}

	count = max(count, solve(x + 1, y, blockCount));

	return count;
}

int main(int argc, char* argv[]) {
	int T, R, C, i;
	char buffer[10][16];

	cin >> T;
	while (T--) {
		cin >> H >> W >> R >> C;
		countSpace = 0;
		i = 0;
		while (i < H) {
			cin >> buffer[0];
			board[i] = row2mask(buffer[0], true);
			i++;
		}
		i = 0;
		while (i < R) {
			cin >> buffer[i];
			i++;
		}
		preCalculateBlocks(buffer, R, C);

		maxBlocks = 0;

		cout << solve(0, 0, 0) << "\n";
	}

	return 0;
}

/*
2
4 7 2 3
##.##..
#......
#....##
#..####
###
#..
5 10 3 3
..........
..........
..........
..........
..........
.#.
###
..#
=====
3
8
*/
