// https://leetcode.com/problems/summary-ranges/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
		string str;
		char buffer[64];
		int from, to, i;

		if (nums.size() == 0) return ranges;

		from = nums[0];
		to = from;
		for (i = 0; i < nums.size(); i++) {
			if (from >= to) {
				from = nums[i];
				to = from + 1;
				itoa(from, buffer, 10);
				str.append(buffer);
			} else {
				if (to == nums[i]) {
					to++;
				} else {
					if (from + 1 < to) {
						str.append("->");
						itoa(to - 1, buffer, 10);
						str.append(buffer);
					}
					ranges.push_back(str);
					str.clear();
					to = from;
					i--;
				}
			}
		}

		if (from < to) {
			if (from + 1 < to) {
				str.append("->");
				itoa(to - 1, buffer, 10);
				str.append(buffer);
			}
			ranges.push_back(str);
		}

		return ranges;
    }
};

int main(int argc, char* argv[]) {
	static const int arr[] = {0, 1, 2, 4, 5, 7};
	vector<int> nums (arr, arr + 6);
	vector<string> ranges;
	Solution s;
	int i;

	ranges = s.summaryRanges(nums);

	for (i = 0; i < ranges.size(); i++) {
		cout << ranges[i] << " ";
	}
	cout << "\n";

	return 0;
}

/*
[0,1,2,4,5,7]
=====
["0->2","4->5","7"]
*/
