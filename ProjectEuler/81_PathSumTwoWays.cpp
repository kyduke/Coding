// https://projecteuler.net/problem=81

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

char buffer[2048];
int matrix[80][80];
int minimals[80][80];

int findMinimalPath(int row, int column) {
	int& ret = minimals[row][column];

	if (ret != -1) return ret;

	if (row == 79 && column == 79) {
		ret = matrix[row][column];
		return ret;
	}

	ret = 2000000000;
	if (row < 79) {
		ret = findMinimalPath(row + 1, column) + matrix[row][column];
	}
	if (column < 79) {
		ret = min(ret, findMinimalPath(row, column + 1) + matrix[row][column]);
	}

	return ret;
}

int main(int argc, char* argv[]) {
	ifstream keyFile;
	int i, j, k, n;

	i = 0;
	keyFile.open("D:/workspace/ProjectEuler_81_PathSumTwoWays/81_PathSumTwoWays.txt");
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

	memset(minimals, -1, sizeof(int) * 80 * 80);

	cout << findMinimalPath(0, 0) << "\n";

	return 0;
}
