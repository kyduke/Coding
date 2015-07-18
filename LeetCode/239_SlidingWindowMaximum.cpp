// https://leetcode.com/problems/sliding-window-maximum/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        multiset<int> sub;
        multiset<int>::iterator it;
        int i;
        
        if (nums.size() == 0) {
            return result;
        }
        
        for (i = 0; i < k; i++) {
            sub.insert(nums[i]);
        }
        
        result.push_back(*(sub.rbegin()));
        for (; i < nums.size(); i++) {
            it = sub.find(nums[i - k]);
            sub.erase(it);
            sub.insert(nums[i]);
            result.push_back(*(sub.rbegin()));
        }
        
        return result;
    }
};

void printArray(vector<int> arr) {
	int i;
	for (i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> nums;
	vector<int> result;

	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(-1);
	nums.push_back(-3);
	nums.push_back(5);
	nums.push_back(3);
	nums.push_back(6);
	nums.push_back(7);

	result = s.maxSlidingWindow(nums, 3);
	printArray(nums);
	printArray(result);

	return 0;
}
