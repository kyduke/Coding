// https://leetcode.com/problems/game-of-life/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copy = board;
		int i, j, w, h, c;

		h = copy.size();
		w = copy[0].size();

		for (j = 0; j < h; j++) {
			for (i = 0; i < w; i++) {
				c = 0;
				if (j > 0 && i > 0) c+= copy[j - 1][i - 1];
				if (j > 0) c+= copy[j - 1][i];
				if (j > 0 && i < w - 1) c+= copy[j - 1][i + 1];
				if (i > 0) c+= copy[j][i - 1];
				if (i < w - 1) c+= copy[j][i + 1];
				if (j < h - 1 && i > 0) c+= copy[j + 1][i - 1];
				if (j < h - 1) c+= copy[j + 1][i];
				if (j < h - 1 && i < w - 1) c+= copy[j + 1][i + 1];

				if (board[j][i] == 1) {
					if (c < 2 || c > 3) board[j][i] = 0;
				} else {
					if (c == 3) board[j][i] = 1;
				}
			}
		}
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<vector<int>> board;
	vector<int> row;
	int i, j;

	row.push_back(1);
	row.push_back(1);
	row.push_back(1);

	board.push_back(row);
	board.push_back(row);
	board.push_back(row);

	for (j = 0; j < board.size(); j++) {
		for (i = 0; i < board[j].size(); i++) {
			cout << board[j][i] << " ";
		}
		cout << "\n";
	}

	s.gameOfLife(board);

	for (j = 0; j < board.size(); j++) {
		for (i = 0; i < board[j].size(); i++) {
			cout << board[j][i] << " ";
		}
		cout << "\n";
	}

	return 0;
}
