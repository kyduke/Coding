// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		vector<vector<int>>::iterator it;
		int i, l, s, e, c;

		if (matrix.size() <= 0) return false;

		l = matrix[0].size() - 1;
		for (it = matrix.begin(); it != matrix.end(); it++) {
			if (*it->begin() > target) break;
			if (*it->rbegin() < target) continue;
			s = 0;
			e = l;
			while (s <= e) {
				i = ((e - s) / 2) + s;
				c = it->at(i);
				if (c == target) {
					return true;
				} else if (c > target) {
					e = i - 1;
				} else {
					s = i + 1;
				}
			}
		}
        
		return false;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<vector<int>> matrix;
	vector<int> row;

	row.clear();
	row.push_back(1);
	row.push_back(4);
	row.push_back(7);
	row.push_back(11);
	row.push_back(15);
	matrix.push_back(row);

	row.clear();
	row.push_back(2);
	row.push_back(5);
	row.push_back(8);
	row.push_back(12);
	row.push_back(19);
	matrix.push_back(row);

	row.clear();
	row.push_back(3);
	row.push_back(6);
	row.push_back(9);
	row.push_back(16);
	row.push_back(22);
	matrix.push_back(row);

	row.clear();
	row.push_back(10);
	row.push_back(13);
	row.push_back(14);
	row.push_back(17);
	row.push_back(24);
	matrix.push_back(row);

	row.clear();
	row.push_back(18);
	row.push_back(21);
	row.push_back(23);
	row.push_back(26);
	row.push_back(30);
	matrix.push_back(row);

	cout << s.searchMatrix(matrix, 5) << "\n";
	cout << s.searchMatrix(matrix, 20) << "\n";

	return 0;
}
