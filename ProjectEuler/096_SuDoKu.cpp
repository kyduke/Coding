// http://projecteuler.net/problem=96

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int puzzles[50][9][9];

void printPuzzle(int puzzle[9][9]) {
	int i, j;
	
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cout << puzzle[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

bool solvePuzzle(int puzzle[9][9]) {
	int i, j, k, candidateCount;
	int x, y;
	int candidate[10] = {0, };

	x = -1;
	y = -1;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (puzzle[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (x >= 0) break;
	}

	if (x == -1) return true;

	for (i = 0; i < 9; i++) {
		candidate[ puzzle[y][i] ] = 1;
		candidate[ puzzle[i][x] ] = 1;
	}

	i = y / 3;
	j = x / 3;
	candidate[ puzzle[i * 3 + 0][j * 3 + 0] ] = 1;
	candidate[ puzzle[i * 3 + 0][j * 3 + 1] ] = 1;
	candidate[ puzzle[i * 3 + 0][j * 3 + 2] ] = 1;

	candidate[ puzzle[i * 3 + 1][j * 3 + 0] ] = 1;
	candidate[ puzzle[i * 3 + 1][j * 3 + 1] ] = 1;
	candidate[ puzzle[i * 3 + 1][j * 3 + 2] ] = 1;

	candidate[ puzzle[i * 3 + 2][j * 3 + 0] ] = 1;
	candidate[ puzzle[i * 3 + 2][j * 3 + 1] ] = 1;
	candidate[ puzzle[i * 3 + 2][j * 3 + 2] ] = 1;

	candidateCount = 0;
	for (k = 1; k < 10; k++) {
		if (candidate[k] == 0) candidateCount++;
	}

	if (candidateCount == 0) return false;

	for (k = 1; k < 10; k++) {
		if (candidate[k] == 0) {
			puzzle[y][x] = k;
			if (solvePuzzle(puzzle) == true) return true;
		}
	}
	puzzle[y][x] = 0;
	
	return false;
}

void solve() {
	int i, sum;

	sum = 0;
	for (i = 0; i < 50; i++) {
		solvePuzzle(puzzles[i]);
		printPuzzle(puzzles[i]);
		sum += puzzles[i][0][0] * 100 + puzzles[i][0][1] * 10 + puzzles[i][0][2];
	}

	cout << sum << "\n";
}

int main(int argc, char* argv[]) {
	ifstream puzzleFile;
	char buffer[10];
	int i, j, k;

	i = 0;
	j = 0;
	puzzleFile.open("D:/workspace/Coding/ProjectEuler_96_SuDoKu/096_SuDoKu.txt");
	while (true) {
		puzzleFile >> buffer;

		if (strlen(buffer) == 9) {
			k = 0;
			while (k < 9) {
				puzzles[i][j][k] = buffer[k] - '0';
				k++;
			}
			j++;
			if (j == 9) {
				i++;
				j = 0;
			}
		}

		if (puzzleFile.eof()) break;
	}
	puzzleFile.close();

	solve();

	return 0;
}
