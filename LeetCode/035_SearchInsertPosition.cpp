// https://leetcode.com/problems/search-insert-position/#/description

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i;
        
        nums.push_back(target);
        sort(nums.begin(), nums.end());
        
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == target) return i;
        }
        
        return 0;
    }
};
