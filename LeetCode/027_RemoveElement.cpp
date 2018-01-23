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

// 2018-01-24
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans, i, j;
        
        ans = 0;
        j = -1;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                if (j == -1) {
                    j = i;
                }
            } else {
                ans++;
                if (j != -1) {
                    nums[j] = nums[i];
                    j++;
                }
            }
        }
        
        return ans;
    }
};
