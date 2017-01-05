// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int i;
        
        sort(nums.begin(), nums.end());
        
        for (i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) return true;
        }
        
        return false;
    }
};
