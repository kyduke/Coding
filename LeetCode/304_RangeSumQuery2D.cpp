// https://leetcode.com/problems/range-sum-query-2d-immutable/

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
private:
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        vector<int> row;
        int i, j, c, r;
        
        if (matrix.size() == 0) return;
        if (matrix[0].size() == 0) return;
        
        c = matrix.size() + 1;
        r = matrix[0].size() + 1;
        row.assign(r, 0);
		for (i = 0; i < c; i++) sums.push_back(row);
        
        //row
        for (i = 1; i < c; i++) {
            for (j = 1; j < r; j++) {
                sums[i][j] = sums[i][j - 1] + matrix[i - 1][j - 1];
            }
        }
        
        //column
        for (i = 1; i < c; i++) {
            for (j = 1; j < r; j++) {
                sums[i][j] += sums[i - 1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (sums.size() == 0) return 0;
        return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] - sums[row2 + 1][col1] + sums[row1][col1];
    }
};

int main(int argc, char* argv[]) {
	vector<vector<int>> matrix;
	vector<int> row;

	row.clear();
	row.push_back(3); row.push_back(0); row.push_back(1); row.push_back(4); row.push_back(2);
	matrix.push_back(row);

	row.clear();
	row.push_back(5); row.push_back(6); row.push_back(3); row.push_back(2); row.push_back(1);
	matrix.push_back(row);

	row.clear();
	row.push_back(1); row.push_back(2); row.push_back(0); row.push_back(1); row.push_back(5);
	matrix.push_back(row);

	row.clear();
	row.push_back(4); row.push_back(1); row.push_back(0); row.push_back(1); row.push_back(7);
	matrix.push_back(row);

	row.clear();
	row.push_back(1); row.push_back(0); row.push_back(3); row.push_back(0); row.push_back(5);
	matrix.push_back(row);

	NumMatrix s(matrix);

	cout << s.sumRegion(2, 1, 4, 3) << "\n";
	cout << s.sumRegion(1, 1, 2, 2) << "\n";
	cout << s.sumRegion(1, 2, 2, 4) << "\n";

	/*
	row.clear();
	row.push_back(-4); row.push_back(-5);
	matrix.push_back(row);

	NumMatrix s(matrix);

	cout << s.sumRegion(0, 0, 0, 0) << "\n";
	cout << s.sumRegion(0, 0, 0, 1) << "\n";
	cout << s.sumRegion(0, 1, 0, 1) << "\n";
	*/
	return 0;
}
