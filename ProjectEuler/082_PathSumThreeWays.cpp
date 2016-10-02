// https://projecteuler.net/problem=82

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

char buffer[2048];
int matrix[80][80];
int minimals[80][80][3];

int findMinimalPath(int row, int column, int rowDirection) {
	int& ret = minimals[row][column][rowDirection];

	if (ret != -1) return ret;

	//cout << row << ", " << column << ", " << rowDirection << "\n";

	if (column == 79) {
		ret = matrix[row][column];
		return ret;
	}

	ret = 2000000000;
	if (row > 0 && rowDirection != 1) {
		ret = findMinimalPath(row - 1, column, 2) + matrix[row][column];
	}
	if (row < 79 && rowDirection != 2) {
		ret = min(ret, findMinimalPath(row + 1, column, 1) + matrix[row][column]);
	}
	if (column < 79) {
		ret = min(ret, findMinimalPath(row, column + 1, 0) + matrix[row][column]);
	}

	return ret;
}

int main(int argc, char* argv[]) {
	ifstream keyFile;
	int i, j, k, n;
	int result;

	i = 0;
	keyFile.open("D:/workspace/ProjectEuler_82_PathSumThreeWays/082_PathSumThreeWays.txt");
	while (true) {
		keyFile >> buffer;
		j = 0;
		k = 0;
		n = 0;
		while (buffer[k] != 0) {
			if (buffer[k] != ',') {
				n = n * 10 + (buffer[k] - '0');
				matrix[i][j] = n;
			} else {
				j++;
				n = 0;
			}
			k++;
		}
		i++;
		if (keyFile.eof()) break;
	}
	keyFile.close();

	memset(minimals, -1, sizeof(int) * 80 * 80 * 3);

	for (j = 79; j > 0; j--) {
		for (i = 0; i < 80; i++) {
			findMinimalPath(i, j, 0);
		}
	}

	result = 2000000000;
	for (i = 0; i < 80; i++) {
		result = min(result, findMinimalPath(i, 0, 0));
	}
	cout << result << "\n";

	return 0;
}
