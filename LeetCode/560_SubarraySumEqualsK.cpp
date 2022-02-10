// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int ans, i, sum;
        
        ans = 0;
        sum = 0;
        m[sum]++;
        for (i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans += m[sum - k];
            m[sum]++;
        }
        
        return ans;
    }
};

