// https://leetcode.com/problems/remove-duplicates-from-sorted-array/#/description

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j;
        
        if (nums.size() <= 1) return nums.size();
        
        j = 1;
        for (i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                j++;
            }
        }
        
        return j;
    }
};

/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j;
        
        if (nums.size() <= 1) return nums.size();
        
        j = 0;
        for (i = 1; i < nums.size(); i++) {
            if (nums[i - 1] != nums[i]) {
                nums[j] = nums[i - 1];
                j++;
                if (i == nums.size() - 1) {
                    nums[j] = nums[i];
                    j++;
                }
            }
        }
        
        if (nums[j - 1] != nums[nums.size() - 1]) {
            nums[j] = nums[nums.size() - 1];
            j++;
        }
        
        if (j == 0) j++;
        
        return j;
    }
};
*/
