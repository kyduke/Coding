// https://leetcode.com/problems/first-missing-positive/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i, j, temp, l;

		l = nums.size();
		i = 0;
		while (i < l) {
			j = nums[i];
			if (j <= 0 || j > l) {
				nums[i] = 0;
				i++;
			} else if (i + 1 == j) {
				i++;
			} else {
				temp = nums[j - 1];
				if (temp == j) {
					nums[i] = 0;
					i++;
				} else {
					nums[j - 1] = j;
					nums[i] = temp;
				}
			}
		}

		for (i = 0; i < l; i++) {
			if (i + 1 != nums[i]) return i + 1;
		}

		return l + 1;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> arr;
	int data[] = {1, 2, 3, 4, 0};

	arr.assign(data, data + 5);

	cout << s.firstMissingPositive(arr) << "\n";

	return 0;
}
