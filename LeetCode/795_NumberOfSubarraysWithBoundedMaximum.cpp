// https://leetcode.com/contest/weekly-contest-74/problems/number-of-subarrays-with-bounded-maximum/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	int calcSubarray(vector<int>& arr, int l, int from, int to) {
		int ans, i, j, currMax;
    
		ans = 0;

		for (i = from; i < to; i++) {
			currMax = l - 1;
			for (j = i; j < to; j++) {
				currMax = max(currMax, arr[j]);
				if (currMax >= l) {
					ans += to - j;
					break;
				}
			}
		}
    
		return ans;
	}
public:
    int numSubarrayBoundedMax(vector<int>& arr, int l, int r) {
        int ans, i, prev, currMax, k;

		ans = 0;
		
		arr.push_back(r + 1);
		prev = -1;
		currMax = l - 1;
		for (i = 0; i < arr.size(); i++) {
			currMax = max(currMax, arr[i]);
			if (prev == -1) prev = i;
			if (currMax > r) {
				k = i - prev;
				if (k > 0) {
					ans += calcSubarray(arr, l, prev, i);
				}
				prev = -1;
				currMax = l - 1;
			}
		}

		return ans;
    }
};

int main(int argc, char** argv) {
	Solution s;
	vector<int> arr;
	
	arr.push_back(2);
	arr.push_back(1);
	arr.push_back(4);
	arr.push_back(3);

	cout << s.numSubarrayBoundedMax(arr, 2, 3) << "\n";
	
	arr.clear();
	arr.push_back(73);
	arr.push_back(55);
	arr.push_back(36);
	arr.push_back(5);
	arr.push_back(55);
	arr.push_back(14);
	arr.push_back(9);
	arr.push_back(7);
	arr.push_back(72);
	arr.push_back(52);

	cout << s.numSubarrayBoundedMax(arr, 32, 69) << "\n";

	return 0;
}

/*
[2, 1, 4, 3], 2, 3
=====
3

[73, 55, 36, 5, 55, 14, 9, 7, 72, 52], 32, 69
=====
22
*/
