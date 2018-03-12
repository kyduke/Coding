// Maximum size rectangle binary sub-matrix with all 1s

#include <iostream>
#include <vector>

using namespace std;

void printBoard(vector<vector<int>>& board) {
	int i, j;

	for (i = 0; i < board.size(); i++) {
		for (j = 0; j < board[i].size(); j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int solve(vector<vector<int>>& board) {
	vector<vector<int>> columnSum;
	int ans, i, j, k, width, height, minHeight;

	ans = 0;

	columnSum = board;
	for (i = columnSum.size() - 2; i >= 0; i--) {
		for (j = 0; j < columnSum[i].size(); j++) {
			columnSum[i][j] = (columnSum[i + 1][j] + columnSum[i][j]) * columnSum[i][j];
		}
	}
	
	printBoard(columnSum);

	height = 0;
	for (i = 0; i < columnSum.size(); i++) {
		for (j = 0; j < columnSum[i].size(); j++) {
			if (columnSum[i][j] == 0) {
				height = 0;
				continue;
			}
			if (columnSum[i][j] <= height) continue;
			height = max(height, columnSum[i][j]);
			minHeight = columnSum[i][j];
			for (k = j; k < columnSum[i].size(); k++) {
				if (columnSum[i][k] == 0) break;
				width = k - j + 1;
				minHeight = min(minHeight, columnSum[i][k]);
				ans = max(ans, width * minHeight);
			}
		}
	}

	return ans;
}


int main(int argc, char** argv) {
	vector<vector<int>> board;
	vector<int> arr;
	int sample1[5][5] = {0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1};
	int sample2[5][5] = {0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1};
	int sample3[5][5] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, j;

	arr.assign(5, 0);
	board.assign(5, arr);

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			board[i][j] = sample1[i][j];
		}
	}
	printBoard(board);
	cout << solve(board) << "\n";

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			board[i][j] = sample2[i][j];
		}
	}
	printBoard(board);
	cout << solve(board) << "\n";

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			board[i][j] = sample3[i][j];
		}
	}
	printBoard(board);
	cout << solve(board) << "\n";

	return 0;
}
