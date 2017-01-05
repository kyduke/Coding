// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int i;
        
        nums.push_back(0);
        nums.push_back(0);
        nums.push_back(0);
        
        for (i = nums.size() - 4; i >= 0; i--) {
            nums[i] = max(nums[i] + nums[i + 2], nums[i] + nums[i + 3]);
        }
        
        return  max(nums[0], nums[1]);
    }
};
