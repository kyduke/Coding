// https://leetcode.com/problems/contains-duplicate-ii/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> m;
		map<int, vector<int>>::iterator it;
		vector<int> arr;
		int i, j;

		for (i = 0; i < nums.size(); i++) {
			it = m.find(nums[i]);
			if (it != m.end()) {
				it->second.push_back(i);
			} else {
				arr.clear();
				arr.push_back(i);
				m.insert(make_pair(nums[i], arr));
			}
		}

		for (it = m.begin(); it != m.end(); it++) {
			arr = it->second;
			for (i = 0; i < arr.size(); i++) {
				for (j = i + 1; j < arr.size(); j++) {
					if (arr[j] - arr[i] <= k) return true;
				}
			}
		}

		return false;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> arr;

	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(2);
	arr.push_back(2);
	arr.push_back(2);

	cout << s.containsNearbyDuplicate(arr, 3) << "\n";

	return 0;
}
