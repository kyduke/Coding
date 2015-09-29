// https://algospot.com/judge/problem/read/BOARDCOVER

#include <iostream>

using namespace std;

int board[20];
int block[4][2] = {
	{3, 2},
	{2, 3},
	{1, 3},
	{3, 1}
};
int maskG = (1 << 20) - 1;
int H, W;

int row2mask(char buffer[32]) {
	int i, mask;

	mask = 0;
	i = 0;
	while (buffer[i] != '\0') {
		mask = mask << 1;
		if (buffer[i] == '#') mask++;
		i++;
	}
	while (i < 20) {
		mask = (mask << 1) + 1;
		i++;
	}

	return mask;
}

int solve(int x, int y) {
	int i, mask0, mask1, count;

	count = 1;
	for (i = 0; i < H; i++) {
		if (board[i] != maskG) {
			count = 0;
			break;
		}
	}

	if (count == 1) return count;

	if (x >= W - 1) {
		x = 0;
		y++;
	}

	if (y >= H - 1) return count;

	for (i = 0; i < 4; i++) {
		mask0 = block[i][0] << (18 - x);
		if (board[y] & mask0) continue;
		mask1 = block[i][1] << (18 - x);
		if (board[y + 1] & mask1) continue;
		board[y] |= mask0;
		board[y + 1] |= mask1;
		count += solve(x + 1, y);
		board[y] &= maskG ^ mask0;
		board[y + 1] &= maskG ^ mask1;
	}

	if (board[y] & (2 << (18 - x))) count += solve(x + 1, y );

	return count;
}

int main(int argc, char* argv[]) {
	int C, i;
	char buffer[32];

	cin >> C;
	while (C--) {
		cin >> H >> W;
		i = 0;
		while(i < H) {
			cin >> buffer;
			board[i] = row2mask(buffer);
			i++;
		}

		cout << solve(0, 0) << "\n";
	}

	return 0;
}

/*
3 
3 7 
#.....# 
#.....# 
##...## 
3 7 
#.....# 
#.....# 
##..### 
8 10 
########## 
#........# 
#........# 
#........# 
#........# 
#........# 
#........# 
##########
=====
0
2
1514
*/
