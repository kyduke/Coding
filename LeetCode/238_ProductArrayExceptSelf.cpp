// https://leetcode.com/problems/product-of-array-except-self/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product, i, zeroCount;
        vector<int> results;
        
        zeroCount = 0;
        product = 1;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroCount++;
                continue;
            }
            product *= nums[i];
        }
        
        if (zeroCount > 1) {
            for (i = 0; i < nums.size(); i++) {
                results.push_back(0);
            }
        } else if (zeroCount == 1) {
            for (i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    results.push_back(product);
                } else {
                    results.push_back(0);
                }
            }
        } else {
            for (i = 0; i < nums.size(); i++) {
                results.push_back(product / nums[i]);
            }
        }
        
        return results;
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

	nums.clear();
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);

	result = s.productExceptSelf(nums);
	printArray(nums);
	printArray(result);

	nums.clear();
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(0);
	nums.push_back(5);

	result = s.productExceptSelf(nums);
	printArray(nums);
	printArray(result);

	nums.clear();
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(0);
	nums.push_back(5);

	result = s.productExceptSelf(nums);
	printArray(nums);
	printArray(result);

	return 0;
}
