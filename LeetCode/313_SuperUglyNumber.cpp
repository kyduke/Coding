// https://leetcode.com/problems/super-ugly-number/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> nums;
		vector<int> curr;
		vector<int> idx;
		int i, j, len;

		len = primes.size();

		nums.assign(n, 0);
		curr.assign(len, 0);
		idx.assign(len, 0);

		nums[0] = 1;
		for (i = 1; i < n; i++) {
			for (j = 0; j < len; j++) {
				curr[j] = nums[ idx[j] ] * primes[j];
				if (nums[i] == 0 || nums[i] > curr[j]) nums[i] = curr[j];
			}
			for (j = 0; j < len; j++) {
				if (curr[j] == nums[i]) idx[j]++;
			}
		}

		return nums[n - 1];
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> arr;
	int data[] = {2, 7, 13, 19};

	arr.assign(data, data + 4);
	cout << s.nthSuperUglyNumber(12, arr) << "\n";

	return 0;
}

/*
12, [2, 7, 13, 19]
=====
32
*/
