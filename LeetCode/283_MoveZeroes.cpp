// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j;
        
        i = 0;
        j = 0;
        while (i < nums.size() && j < nums.size()) {
            while (j < nums.size()) {
                if (nums[j] == 0) break;
                j++;
            }
            i = j + 1;
            while (i < nums.size()) {
                if (nums[i] != 0) {
                    nums[j] = nums[i];
                    nums[i] = 0;
                    j++;
                    break;
                }
                i++;
            }
        }
    }
};

/*
0, 1, 0, 3, 12
=====
1, 3, 12, 0, 0
*/
