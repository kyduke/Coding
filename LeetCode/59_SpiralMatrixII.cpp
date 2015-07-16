// https://leetcode.com/problems/spiral-matrix-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	vector<int> shell;
	int width;
	int height;
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
	int getIndex(int y, int x) {
		int w, h, s, n;

		w = width;
		h = height;
		s = min(min(y, (h - 1) - y), min(x, (w - 1) - x));
		w = width - s * 2;
		h = height - s * 2;

		n = -1;
		if (y == s && x >= s && x < (w - 1) + s) {
			n = shell[s] + x - s;
		} else if (y >= s && y < (h - 1) + s && x == (w - 1) + s) {
			n = shell[s] + (w - 1) - s + y;
		} else if (y == (h - 1) + s && x > s && x <= (w - 1) + s) {
			n = shell[s] + (w - 1) + (w - 1) + (h - 1) + s - x;
		} else {
			n = shell[s] + (w - 1) + (w - 1) + (h - 1) + (h - 1) + s - y;
		}


		return n;
	};
public:
	vector<vector<int>> generateMatrix(int height, int width) {
        vector<vector<int>> matrix;
		vector<int> v;
		int i, j, n;

		this->width = width;
		this->height = height;

		fillShell();

		for (i = 0; i < height; i++) {
			v.clear();
			for (j = 0; j < width; j++) {
				n = getIndex(i, j) + 1;
				v.push_back(n);
			}
			matrix.push_back(v);
		}

		return matrix;
    }
};

void printVector(vector<vector<int>>& v) {
	int i, j, w, h;

	w = v[0].size();
	h = v.size();
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(int argc, char* argv) {
	vector<vector<int>> matrix;
	Solution s;

	matrix = s.generateMatrix(3, 3);
	printVector(matrix);

	matrix = s.generateMatrix(1, 7);
	printVector(matrix);

	matrix = s.generateMatrix(5, 8);
	printVector(matrix);

	matrix = s.generateMatrix(6, 8);
	printVector(matrix);

	matrix = s.generateMatrix(5, 5);
	printVector(matrix);

	matrix = s.generateMatrix(8, 8);
	printVector(matrix);

	matrix = s.generateMatrix(1, 1);
	printVector(matrix);

	return 0;
}
