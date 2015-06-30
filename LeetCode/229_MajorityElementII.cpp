// https://leetcode.com/problems/majority-element-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
		int n;
		int i, j, c;

		n = nums[0] - 1;
		j = 0;
		while (j < nums.size()) {
			while (j < nums.size()) {
				if (n != nums[j]) {
					n = nums[j];
					c = 1;
					break;
				}
				j++;
			}

			for (i = j + 1; i < nums.size(); i++) {
				if (n == nums[i]) {
					c++;
					if (c > nums.size() / 3) {
						result.push_back(n);
						break;
					}
				}
			}
		}

		return result;
    }
};

int main(int argc, char* argv[]) {
	int arr[] = {1, 7, 5, 7, 5, 7, 5, 2, 7, 5};
	vector<int> nums(arr, arr + 10);
	vector<int> result;
	Solution s;
	int i;

	result = s.majorityElement(nums);
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	return 0;
}
