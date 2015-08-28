// https://leetcode.com/problems/missing-number/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
		vector<int> temp;
		int left, mid, right;

		temp = nums;
		sort(temp.begin(), temp.end());

		left = 0;
		right = temp.size() - 1;

		while (left < right) {
			mid = (right - left) / 2 + left;
			if (mid == temp[mid]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}

		if (left == temp[left]) return temp[left] + 1;

        return temp[left] - 1;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> nums;

	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	//nums.push_back(8);
	nums.push_back(9);
	nums.push_back(10);
	nums.push_back(11);
	nums.push_back(12);

	cout << s.missingNumber(nums) << "\n";

	return 0;
}
