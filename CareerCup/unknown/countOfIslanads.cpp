// http://careercup.com/question?id=5708658983829504

#include <iostream>
#include <vector>

using namespace std;

int countOfIslands(vector<vector<int>> matrix) {
	vector<vector<int>> groupMatrix;
	vector<int> groupID;
	int nextGroup;
	int i, x, y, left, up, cnt;

	groupMatrix = matrix;
	for (i = 0; i < groupMatrix.size(); i++) {
		groupMatrix[i].assign(groupMatrix[i].size(), 0);
	}

	groupID.push_back(0);
	nextGroup = 1;

	for (y = 0; y < matrix.size(); y++) {
		for (x = 0; x < matrix[y].size(); x++) {
			if (matrix[y][x] == 0) continue;

			left = 0;
			if (x != 0) left = groupMatrix[y][x - 1];
			left = groupID[left];

			up = 0;
			if (y != 0) up = groupMatrix[y - 1][x];
			up = groupID[up];

			if (left == 0 && up == 0) {
				groupMatrix[y][x] = nextGroup;
				groupID.push_back(nextGroup);
				nextGroup++;
			} else if (left != 0 && up != 0) {
				if (left > up) {
					groupMatrix[y][x] = up;
					groupID[left] = up;
				} else {
					groupMatrix[y][x] = left;
					groupID[up] = left;
				}
			} else if (up == 0) {
				groupMatrix[y][x] = left;
			} else {
				groupMatrix[y][x] = up;
			}
		}
	}

	cnt = 0;
	for (i = 1; i < groupID.size(); i++) {
		if (i == groupID[i]) cnt++;
	}

	return cnt;
}

int main(int argc, char* argv[]) {
	vector<vector<int>> matrix;
	vector<int> row;

	matrix.clear();

	row.clear();
	row.push_back(0);
	row.push_back(1);
	row.push_back(0);
	row.push_back(1);
	row.push_back(0);
	matrix.push_back(row);

	row.clear();
	row.push_back(0);
	row.push_back(0);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	matrix.push_back(row);

	row.clear();
	row.push_back(1);
	row.push_back(0);
	row.push_back(0);
	row.push_back(1);
	row.push_back(0);
	matrix.push_back(row);

	row.clear();
	row.push_back(0);
	row.push_back(1);
	row.push_back(1);
	row.push_back(0);
	row.push_back(0);
	matrix.push_back(row);

	row.clear();
	row.push_back(1);
	row.push_back(0);
	row.push_back(1);
	row.push_back(0);
	row.push_back(1);
	matrix.push_back(row);

	cout << countOfIslands(matrix) << "\n";

	matrix.clear();

	row.clear();
	row.push_back(0);
	row.push_back(0);
	row.push_back(1);
	row.push_back(1);
	row.push_back(0);
	matrix.push_back(row);

	row.clear();
	row.push_back(1);
	row.push_back(0);
	row.push_back(1);
	row.push_back(0);
	row.push_back(1);
	matrix.push_back(row);

	row.clear();
	row.push_back(1);
	row.push_back(0);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	matrix.push_back(row);

	row.clear();
	row.push_back(1);
	row.push_back(0);
	row.push_back(0);
	row.push_back(0);
	row.push_back(1);
	matrix.push_back(row);

	row.clear();
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	matrix.push_back(row);

	cout << countOfIslands(matrix) << "\n";

	return 0;
}
