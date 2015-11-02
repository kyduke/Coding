// Spiral Move

#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>>& matrix) {
	int i, j;

	for (i = 0; i < matrix.size(); i++) {
		for (j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void spiralMove(vector<vector<int>>& matrix) {
	vector<int> arr;
	vector<vector<int>> copy;
	vector<vector<int>> shell;
	vector<int> last;
	int i, j, row, column, s, d;

	row = matrix.size();
	if (row == 0) return;
	column = matrix[0].size();
	if (column == 0) return;

	for (i = 0; i < row; i++) {
		arr.clear();
		arr.assign(column, -1);
		shell.push_back(arr);
		copy.push_back(arr);
	}

	//shell
	last.assign((min(row, column) + 1) / 2, 0);
	s = 0;
	d = 0;
	i = 0;
	j = 0;
	while (true) {
		if (i == row || j == column) break;
		if (shell[i][j] != -1) break;
		shell[i][j] = s;
		last[s] = matrix[i][j];
		if (d == 0) {
			if (j < column - 1 && shell[i][j + 1] == -1) {
				j++;
			} else {
				i++;
				d = 1;
			}
			continue;
		} else if (d == 1) {
			if (i < row - 1 && shell[i + 1][j] == -1) {
				i++;
			} else {
				j--;
				d = 2;
			}
			continue;
		} else if (d == 2) {
			if (j > 0 && shell[i][j - 1] == -1) {
				j--;
			} else {
				i--;
				d = 3;
			}
			continue;
		} else {
			if (i > 0 && shell[i - 1][j] == -1) {
				i--;
			} else {
				s++;
				j++;
				d = 0;
			}
			continue;
		}
	}

	// move
	s = 0;
	d = 0;
	i = 0;
	j = 0;
	while (true) {
		if (i == row || j == column) break;
		if (shell[i][j] != s) break;
		copy[i][j] = last[s];
		last[s] = matrix[i][j];
		shell[i][j] = -1;
		if (d == 0) {
			if (j < column - 1 && shell[i][j + 1] == s) {
				j++;
			} else {
				i++;
				d = 1;
			}
			continue;
		} else if (d == 1) {
			if (i < row - 1 && shell[i + 1][j] == s) {
				i++;
			} else {
				j--;
				d = 2;
			}
			continue;
		} else if (d == 2) {
			if (j > 0 && shell[i][j - 1] == s) {
				j--;
			} else {
				i--;
				d = 3;
			}
			continue;
		} else {
			if (i > 0 && shell[i - 1][j] == s) {
				i--;
			} else {
				s++;
				j++;
				d = 0;
			}
			continue;
		}
	}

	matrix = copy;
}

int main(int argc, char* argv[]) {
	vector<vector<int>> matrix;
	vector<int> arr;

	arr.clear();
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	matrix.push_back(arr);

	arr.clear();
	arr.push_back(14);
	arr.push_back(15);
	arr.push_back(16);
	arr.push_back(17);
	arr.push_back(6);
	matrix.push_back(arr);

	arr.clear();
	arr.push_back(13);
	arr.push_back(20);
	arr.push_back(19);
	arr.push_back(18);
	arr.push_back(7);
	matrix.push_back(arr);

	arr.clear();
	arr.push_back(12);
	arr.push_back(11);
	arr.push_back(10);
	arr.push_back(9);
	arr.push_back(8);
	matrix.push_back(arr);

	printMatrix(matrix);

	spiralMove(matrix);
	printMatrix(matrix);

	spiralMove(matrix);
	printMatrix(matrix);

	return 0;
}
