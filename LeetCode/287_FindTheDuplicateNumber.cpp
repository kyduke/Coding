//
//  main.cpp
//  LeetCode_287_FindTheDuplicateNumber
//
//  Created by Youngduke Koh on 9/28/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//

// https://leetcode.com/problems/find-the-duplicate-number/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> copy = nums;
        int i;
        
        sort(copy.begin(), copy.end());
        
        for (i = 0; i < copy.size() - 1; i++) {
            if (copy[i] == copy[i + 1]) return copy[i];
        }
        
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 2, 8, 9};
    vector<int> nums;
    
    nums.assign(arr, arr + 10);
    
    cout << s.findDuplicate(nums) << "\n";
    
    return 0;
}
