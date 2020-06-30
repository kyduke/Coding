// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        vector<long long> cnt;
        long long ans, modulo;
        int i, j, l, r, mid, t;
        
        modulo = 1000000007;
        
        cnt.assign(nums.size() + 1, 0);
        cnt[0] = 1;
        for (i = 1; i <= nums.size(); i++) {
            cnt[i] = (cnt[i - 1] * 2) % modulo;
            cnt[i - 1]--;
        }
        
        sort(nums.begin(), nums.end());
        
        if (nums[nums.size() - 1] + nums[nums.size() - 1] <= target) {
            ans = nums.size();
        } else {
            l = 0;
            r = nums.size();
            t = (target / 2) + 1;
            while (l < r) {
                mid = (l + r) / 2;
                if (nums[mid] < t) {
                    if (l == mid) mid++;
                    l = mid;
                } else {
                    r = mid;
                }
            }
            ans = l;
        }
        
        i = 0;
        j = nums.size() - 1;
        while (i <= j) {
            while (j >= 0 && nums[i] + nums[j] > target) {
                j--;
            }
            if (j > i) {
                ans = (ans + cnt[j - i]) % modulo;
            }
            i++;
        }
        
        return ans;
    }
};

/*
[3,5,6,7] 9
=====
4

[3,3,6,8] 10
=====
6

[2,3,3,4,6,7] 12
=====
61

[5,2,4,1,7,6,8] 16
=====
127
*/
