// https://leetcode.com/problems/pacific-atlantic-water-flow/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> ans;
		vector<vector<int>> pacific, atlantic;
		vector<int> arr;
		queue<pair<int, int>> q;
		int i, j, k, w, h;

		h = matrix.size();
		if (h == 0) {
			return ans;
		}
		w = matrix[0].size();
		if (w == 0) {
			return ans;
		}

		arr.assign(w, 0);
		for (i = 0; i < h; i++) {
			pacific.push_back(arr);
			atlantic.push_back(arr);
		}

		for (i = 0; i < w; i++) {
			pacific[0][i] = 1;
			q.push(make_pair(0, i));
		}
		for (i = 1; i < h; i++) {
			pacific[i][0] = 1;
			q.push(make_pair(i, 0));
		}
		while (!q.empty()) {
			i = q.front().first;
			j = q.front().second;
			q.pop();

			k = matrix[i][j];
			if (i > 0 && pacific[i - 1][j] == 0 && matrix[i - 1][j] >= k) {
				pacific[i - 1][j] = 1;
				q.push(make_pair(i - 1, j));
			}
			if (j > 0 && pacific[i][j - 1] == 0 && matrix[i][j - 1] >= k) {
				pacific[i][j - 1] = 1;
				q.push(make_pair(i, j - 1));
			}
			if (i < h - 1 && pacific[i + 1][j] == 0 && matrix[i + 1][j] >= k) {
				pacific[i + 1][j] = 1;
				q.push(make_pair(i + 1, j));
			}
			if (j < w - 1 && pacific[i][j + 1] == 0 && matrix[i][j + 1] >= k) {
				pacific[i][j + 1] = 1;
				q.push(make_pair(i, j + 1));
			}
		}

		for (i = 0; i < w; i++) {
			atlantic[h - 1][i] = 1;
			q.push(make_pair(h - 1, i));
		}
		for (i = 0; i < h - 1; i++) {
			atlantic[i][w - 1] = 1;
			q.push(make_pair(i, w - 1));
		}
		while (!q.empty()) {
			i = q.front().first;
			j = q.front().second;
			q.pop();

			k = matrix[i][j];
			if (i > 0 && atlantic[i - 1][j] == 0 && matrix[i - 1][j] >= k) {
				atlantic[i - 1][j] = 1;
				q.push(make_pair(i - 1, j));
			}
			if (j > 0 && atlantic[i][j - 1] == 0 && matrix[i][j - 1] >= k) {
				atlantic[i][j - 1] = 1;
				q.push(make_pair(i, j - 1));
			}
			if (i < h - 1 && atlantic[i + 1][j] == 0 && matrix[i + 1][j] >= k) {
				atlantic[i + 1][j] = 1;
				q.push(make_pair(i + 1, j));
			}
			if (j < w - 1 && atlantic[i][j + 1] == 0 && matrix[i][j + 1] >= k) {
				atlantic[i][j + 1] = 1;
				q.push(make_pair(i, j + 1));
			}
		}

		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
					ans.push_back(make_pair(i, j));
				}
			}
		}

		return ans;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<vector<int>> matrix;
	vector<int> arr;
	vector<pair<int, int>> result;
	int i;

	arr.assign(5, 0);
	matrix.push_back(arr);
	matrix.push_back(arr);
	matrix.push_back(arr);
	matrix.push_back(arr);
	matrix.push_back(arr);

	matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 2; matrix[0][3] = 3; matrix[0][4] = 5;
	matrix[1][0] = 3; matrix[1][1] = 2; matrix[1][2] = 3; matrix[1][3] = 4; matrix[1][4] = 4;
	matrix[2][0] = 2; matrix[2][1] = 4; matrix[2][2] = 5; matrix[2][3] = 3; matrix[2][4] = 1;
	matrix[3][0] = 6; matrix[3][1] = 7; matrix[3][2] = 1; matrix[3][3] = 4; matrix[3][4] = 5;
	matrix[4][0] = 5; matrix[4][1] = 1; matrix[4][2] = 1; matrix[4][3] = 2; matrix[4][4] = 4;

	result = s.pacificAtlantic(matrix);
	for (i = 0; i < result.size(); i++) {
		cout << "(" << result[i].first << ", " << result[i].second << ")\n"; 
	}

	return 0;
}
