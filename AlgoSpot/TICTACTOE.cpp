// https://algospot.com/judge/problem/read/TICTACTOE

#include <iostream>
#include <string.h>

using namespace std;

const int SIZE = 19683;

int cache[SIZE];
int board[3][3] = {0, };

int getIndex() {
	int i, j, index;

	index = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			index = index * 3 + board[i][j];
		}
	}

	return index;
}

int findWinner() {
	if (board[0][0] != 0 && board[0][0] == board[0][1] && board[0][0] == board[0][2]) return board[0][0];
	if (board[1][0] != 0 && board[1][0] == board[1][1] && board[1][0] == board[1][2]) return board[1][0];
	if (board[2][0] != 0 && board[2][0] == board[2][1] && board[2][0] == board[2][2]) return board[2][0];

	if (board[0][0] != 0 && board[0][0] == board[1][0] && board[0][0] == board[2][0]) return board[0][0];
	if (board[0][1] != 0 && board[0][1] == board[1][1] && board[0][1] == board[2][1]) return board[0][1];
	if (board[0][2] != 0 && board[0][2] == board[1][2] && board[0][2] == board[2][2]) return board[0][2];

	if (board[0][0] != 0 && board[0][0] == board[1][1] && board[0][0] == board[2][2]) return board[0][0];
	if (board[0][2] != 0 && board[0][2] == board[1][1] && board[0][2] == board[2][0]) return board[0][2];

	return 0;
}

int preCalc(int turn) {
	int i, j, winner;
	int result[3] = {0, };
	
	int& ret = cache[getIndex()]; //0: TIE, 1: first turn, 2: second turn

	if (ret != -1) return ret;

	winner = findWinner();
	if (winner > 0) {
		ret = winner;
		return ret;
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (board[i][j] == 0) {
				board[i][j] = turn;
				result[preCalc((turn % 2) + 1)] = 1;
				board[i][j] = 0;
			}
		}
	}

	ret = 0;
	if (result[turn] == 1) {
		ret = turn;
	} else if (result[0] == 1) {
		ret = 0;
	} else if (result[(turn % 2) + 1]) {
		ret = (turn % 2) + 1;
	}

	return ret;
}

int charToStone(char c) {
	if (c == 'x') return 1;
	if (c == 'o') return 2;
	return 0;
}

int main(int argc, char* argv[]) {
	int C;
	char buffer[4];

	memset(cache, -1, sizeof(int) * SIZE);

	preCalc(1);

	cin >> C;
	while (C--) {
		cin >> buffer;
		board[0][0] = charToStone(buffer[0]);
		board[0][1] = charToStone(buffer[1]);
		board[0][2] = charToStone(buffer[2]);

		cin >> buffer;
		board[1][0] = charToStone(buffer[0]);
		board[1][1] = charToStone(buffer[1]);
		board[1][2] = charToStone(buffer[2]);

		cin >> buffer;
		board[2][0] = charToStone(buffer[0]);
		board[2][1] = charToStone(buffer[1]);
		board[2][2] = charToStone(buffer[2]);

		switch (cache[getIndex()]) {
			case 1:
				cout << "x\n";
				break;
			case 2:
				cout << "o\n";
				break;
			default:
				cout << "TIE\n";
		}
	}

	return 0;
}

/*
3
...
...
...
xx.
oo.
...
xox
oo.
x.x
=====
TIE
x
o

1
o.o
x..
.x.
=====
o

1
oxx
...
...
=====
o
*/
