// https://leetcode.com/problems/majority-element-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
	int n;
	int i, j, c, n3;
	
	if (nums.size() == 0) return result;

        n3 = nums.size() / 3;
	n = 0;
	j = 0;
	while (j < nums.size()) {
		while (j < nums.size()) {
			if (find(result.begin(), result.end(), nums[j]) == result.end()) {
				n = nums[j];
				c = 1;
				j++;
				break;
			}
			c = 0;
			j++;
		}

		for (i = j; i < nums.size(); i++) {
			if (n == nums[i]) {
				c++;
				if (c > n3) break;
			}
		}
		
		if (c > n3) {
		    result.push_back(n);
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
