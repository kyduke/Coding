// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int i, j;

		for (i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) {
				j = nums[i] - 1;
			} else {
				j = -nums[i] - 1;
			}
			if (nums[j] < 0) continue;
			nums[j] = -nums[j];
		}
        
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};

class Solution2 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int i, j, k;

		if (nums.size() == 0) return ans;

		j = 0;
		i = nums[j] - 1;
		nums[j] = 0;
		while (true) {
			k = nums[i] - 1;
			nums[i] = i + 1;
			if (k == i || k < 0) {
				j++;
				if (j >= nums.size()) break;
				i = nums[j] - 1;
				nums[j] = 0;
			} else {
				i = k;
			}
		}
        
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};

class Solution3 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans, arr;
        int i;
        
        arr.assign(nums.size(), 0);
        
        for (i = 0; i < nums.size(); i++) {
            arr[ nums[i] - 1] = 1;
        }
        
        for (i = 0; i < nums.size(); i++) {
            if (arr[i] == 0) {
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	Solution2 s2;
	Solution3 s3;
	vector<int> arr, ans;
	int i;

	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(7);
	arr.push_back(8);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(1);

	ans = s.findDisappearedNumbers(arr);
	for (i = 0; i < ans.size(); i++) {
		cout << ans[i] << ", ";
	}
	cout << "\n";

	arr.clear();
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(7);
	arr.push_back(8);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(1);

	ans = s2.findDisappearedNumbers(arr);
	for (i = 0; i < ans.size(); i++) {
		cout << ans[i] << ", ";
	}
	cout << "\n";

	arr.clear();
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(7);
	arr.push_back(8);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(1);

	ans = s3.findDisappearedNumbers(arr);
	for (i = 0; i < ans.size(); i++) {
		cout << ans[i] << ", ";
	}
	cout << "\n";

	return 0;
}

/*
4, 3, 2, 7, 8, 2, 3, 1
=====
5, 6
*/
