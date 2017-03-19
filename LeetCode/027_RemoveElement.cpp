// https://leetcode.com/problems/remove-element/#/description

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans, i, j;
        
        ans = nums.size();
        j = nums.size() - 1;
        for (i = 0; i < ans; i++) {
            if (nums[i] == val) {
                nums[i] = nums[j]; 
                ans--;
                i--;
                j--;
            }
        }
        
        return ans;
    }
};
