// https://leetcode.com/problems/wiggle-sort-ii/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> copy;
        int i, j;
        
        copy = nums;
        sort(copy.begin(), copy.end());
        
        i = (copy.size() + 1) / 2 - 1;
        for (j = 0; j < copy.size(); j += 2, i--) {
            nums[j] = copy[i];
        }
        
        i = copy.size() - 1;
        for (j = 1; j < copy.size(); j += 2, i--) {
            nums[j] = copy[i];
        }
    }
};

/*
1, 5, 1, 1, 6, 4
=====
1, 4, 1, 5, 1, 6

1, 3, 2, 2, 3, 1
=====
2, 3, 1, 3, 1, 2

4, 5, 5, 6
=====
5, 6, 4, 5
*/
