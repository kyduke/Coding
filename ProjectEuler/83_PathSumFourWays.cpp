// https://projecteuler.net/problem=83

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

typedef pair<int, int> point;

char buffer[2048];
int matrix[80][80];
int visits[80][80] = {0, };

int findMinimalPathAStar() {
	multimap<int, point> candidate;
	multimap<int, point>::iterator it;
	int result, row, column;

	candidate.insert(make_pair(matrix[0][0], make_pair(0, 0)));

	while (candidate.empty() == false) {
		it = candidate.begin();
		result = it->first;
		row = it->second.first;
		column = it->second.second;
		if (row == 79 && column == 79) {
			candidate.clear();
			break;
		}

		visits[row][column] = 1;
		if (row > 0 && visits[row - 1][column] == 0) {
			candidate.insert(make_pair(result + matrix[row - 1][column], make_pair(row - 1, column)));
		}
		if (row < 79 && visits[row + 1][column] == 0) {
			candidate.insert(make_pair(result + matrix[row + 1][column], make_pair(row + 1, column)));
		}
		if (column > 0 && visits[row][column - 1] == 0) {
			candidate.insert(make_pair(result + matrix[row][column - 1], make_pair(row, column - 1)));
		}
		if (column < 79 && visits[row][column + 1] == 0) {
			candidate.insert(make_pair(result + matrix[row][column + 1], make_pair(row, column + 1)));
		}
		candidate.erase(it);
	}

	return result;
}

int main(int argc, char* argv[]) {
	ifstream keyFile;
	int i, j, k, n;

	i = 0;
	keyFile.open("D:/workspace/ProjectEuler_83_PathSumFourWays/83_PathSumFourWays.txt");
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

	cout << findMinimalPathAStar() << "\n";

	return 0;
}
