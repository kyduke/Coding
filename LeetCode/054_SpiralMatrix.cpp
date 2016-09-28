// https://leetcode.com/problems/spiral-matrix/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	vector<int> shell;
	int width;
	int height;
	int x;
	int y;
	void fillShell() {
		int count;
		int w, h, n, shellDepth;

		shell.clear();

		count = width * height;
		w = width;
		h = height;
		shellDepth = 0;
		shell.push_back(shellDepth);
		while (count > 0) {
			if (w > 1 && h > 1) {
				n = w + w + h + h - 4;
			} else {
				n = max(w, h);
			}
			shell.push_back(n + shell[shellDepth]);
			shellDepth++;
			count -= n;
			w -= 2;
			h -= 2;
		}
	}
	void findXY(int n) {
		int w, h, s;
		int i;

		s = 0;
		for (i = 1; i < shell.size(); i++) {
			if (n < shell[i]) {
				s = i - 1;
				break;
			}
		}

		n -= shell[s];
		w = width - s * 2;
		h = height - s * 2;

		if (n < (w - 1)) {
			x = n + s;
			y = s;
		} else if (n < (w - 1) + (h - 1)) {
			x = (w - 1) + s;
			y = n - (w - 1) + s;
		} else if (n < (w - 1) + (h - 1) + (w - 1)) {
			x = (w - 1) - (n - (w - 1) - (h - 1)) + s;
			y = (h - 1) + s;
		} else {
			x = s;
			y = (h - 1) - (n - (w - 1) - (h - 1) - (w - 1)) + s;
		}
	}
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
		int i;

		width = matrix[0].size();
		height = matrix.size();

		fillShell();

		for (i = 0; i < width * height; i++) {
			findXY(i);
			result.push_back(matrix[y][x]);
		}

		return result;
    }
};

vector<int> makeVectorFromArray(int* arr, int n) {
	vector<int> v;
	int i;
	for (i = 0; i < n; i++) {
		v.push_back(arr[i]);
	}
	return v;
}

void printVector(vector<int>& v) {
	int i;
	for (i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

int main(int argc, char* argv) {
	vector<vector<int>> matrix;
	int arr[5][8] = {
		{ 1,  2,  3,  4,  5,  6,  7,  8},
		{22, 23, 24, 25, 26, 27, 28,  9},
		{21, 36, 37, 38, 39, 40, 29, 10},
		{20, 35, 34, 33, 32, 31, 30, 11},
		{19, 18, 17, 16, 15, 14, 13, 12}
	};
	/*
	int arr[6][8] = {
		{ 1,  2,  3,  4,  5,  6,  7,  8},
		{24, 25, 26, 27, 28, 29, 30,  9},
		{23, 40, 41, 42, 43, 44, 31, 10},
		{22, 39, 48, 47, 46, 45, 32, 11},
		{21, 38, 37, 36, 35, 34, 33, 12},
		{20, 19, 18, 17, 16, 15, 14, 13}
	};
	*/
	Solution s;
	vector<int> result;

	matrix.push_back(makeVectorFromArray(arr[0], 8));
	matrix.push_back(makeVectorFromArray(arr[1], 8));
	matrix.push_back(makeVectorFromArray(arr[2], 8));
	matrix.push_back(makeVectorFromArray(arr[3], 8));
	matrix.push_back(makeVectorFromArray(arr[4], 8));
	//matrix.push_back(makeVectorFromArray(arr[5], 8));

	result = s.spiralOrder(matrix);

	printVector(result);

	return 0;
}
