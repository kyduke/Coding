// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
		int i, m, ans;

		m = 2147483647;
		for (i = 0; i < nums.size(); i++) {
			m = min(m, nums[i]);
		}

		ans = 0;
		for (i = 0; i < nums.size(); i++) {
			ans += nums[i] - m;
		}

		return ans;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> arr;

	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);

	cout << s.minMoves(arr) << "\n";

	return 0;
}
