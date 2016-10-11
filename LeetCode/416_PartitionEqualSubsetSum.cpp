// https://leetcode.com/problems/partition-equal-subset-sum/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
		set<int> s, t;
		set<int>::iterator it;
        int sum, temp, i;
		
		sum = 0;
		for (i = 0; i < nums.size(); i++) {
			sum += nums[i];
		}

		if (sum % 2 == 1) {
			return false;
		}

		sum /= 2;

		s.insert(0);
		for (i = 0; i < nums.size(); i++) {
			if (i % 2 == 0) {
				for (it = s.begin(); it != s.end(); it++) {
					temp = *it + nums[i];
					if (temp == sum) {
						return true;
					} else if (temp > sum) {
						break;
					}
					t.insert(temp);
				}
			} else {
				for (it = t.begin(); it != t.end(); it++) {
					temp = *it + nums[i];
					if (temp == sum) {
						return true;
					} else if (temp > sum) {
						break;
					}
					s.insert(temp);
				}
			}
		}

		return false;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> arr;
	int data[] = {1, 2, 3, 5, 6, 7, 8, 10};

	arr.assign(data, data + 8);
	cout << s.canPartition(arr);

	return 0;
}
