// https://leetcode.com/problems/third-maximum-number/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long f, s, t, a, b, i;
        
        f = nums[0];
        s = -2147483649;
        t = -2147483649;
        a = b = 0;
        for (i = 1; i < nums.size(); i++) {
            if (nums[i] == f || nums[i] == s) continue;
            if (nums[i] > f) {
                t = s;
                s = f;
                f = nums[i];
                if (a == 1) b = 1;
                a = 1;
            } else if (nums[i] > s) {
                t = s;
                s = nums[i];
                if (a == 1) b = 1;
                a = 1;
            } else if (nums[i] > t) {
                t = nums[i];
                b = 1;
            }
        }
        
        return (b == 1) ? t : f;
    }
};
