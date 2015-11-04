// https://leetcode.com/problems/longest-increasing-subsequence/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		vector<pair<int, int>> subs;
		vector<pair<int, int>> copy;
        int i, j, l, length;

        for (i = 0; i < nums.size(); i++) {
			l = subs.size();
			length = 0;
            for (j = 0; j < l; j++) {
				if (subs[j].second < nums[i]) {
					if (length <= subs[j].first) length = subs[j].first + 1;
				}
			}
			if (length == 0) {
				subs.push_back(make_pair(1, nums[i]));
			} else {
				copy = subs;
				subs.clear();
				for (j = 0; j < copy.size(); j++) {
					if (copy[j].first >= length || copy[j].second <= nums[i]) {
						subs.push_back(copy[j]);
					}
				}
				subs.push_back(make_pair(length, nums[i]));
				copy.clear();
			}
        }

		length = 0;
		for (i = 0; i < subs.size(); i++) {
			if (length < subs[i].first) length = subs[i].first;
		}
        
        return length;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	int data[] = {10, 9, 2, 5, 3, 7, 101, 18};
	vector<int> arr(data, data + 8);

	cout << s.lengthOfLIS(arr) << "\n";

	return 0;
}
