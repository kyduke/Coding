// https://leetcode.com/problems/burst-balloons/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
		vector<vector<int>> cache;
		vector<int> copy;
		vector<int> v;
		int i, l, r, m, n, t;

		copy.push_back(1);
		for (i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) continue;
			copy.push_back(nums[i]);
		}
		copy.push_back(1);

		n = copy.size();

		v.assign(n, 0);
		for (i = 0; i < n; i++) {
			cache.push_back(v);
		}

		for (i = 2; i < n; i++) {
			for (l = 0; l < n - i; l++) {
				r = l + i;
				for (m = l + 1; m < r; m++) {
					t = copy[l] * copy[m] * copy[r] + cache[l][m] + cache[m][r];
					if (cache[l][r] < t) cache[l][r] = t;
				}
			}
		}
		
		return cache[0][n - 1];
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> arr;
	//int data[] = {3, 1, 5, 8};
	int data[] = {9, 76, 64, 21, 97, 60, 5};

	arr.assign(data, data + 7);
	cout << s.maxCoins(arr) << "\n";

	return 0;
}

/*
[3, 1, 5, 8]
=====
167
*/
