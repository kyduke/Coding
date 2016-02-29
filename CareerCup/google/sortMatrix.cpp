// https://careercup.com/question?id=5174694727647232

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printMatrix(vector<vector<int>>& matrix) {
	int column, row, i, j;

	column = matrix.size();
	if (column == 0) return;
	
	row = matrix[0].size();
	for (i = 0; i < column; i++) {
		for (j = 0; j < row; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

void sortMatrix(vector<vector<int>>& matrix) {
	int column, row, i, j, k;
	vector<int> arr;

	column = matrix.size();
	if (column == 0) return;
	
	row = matrix[0].size();
	arr.assign(column * row, 0);
	for (i = 0; i < column; i++) {
		k = i * row;
		for (j = 0; j < row; j++) {
			arr[k + j] = matrix[i][j];
		}
	}
	sort(arr.begin(), arr.end());
	for (j = 0; j < row; j++) {
		k = j * column;
		for (i = 0; i < column; i++) {
			matrix[i][j] = arr[k + i];
		}
	} 
}

int main(int argc, char* argv[]) {
	vector<vector<int>> matrix;
	vector<int> arr;

	arr.clear();
	arr.push_back(1);
	arr.push_back(3);
	arr.push_back(5);
	matrix.push_back(arr);

	arr.clear();
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	matrix.push_back(arr);

	printMatrix(matrix);
	sortMatrix(matrix);
	printMatrix(matrix);

	return 0;
}
