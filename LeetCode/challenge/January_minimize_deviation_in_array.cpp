// https://leetcode.com/explore/featured/card/january-leetcoding-challenge-2021/583/week-5-january-29th-january-31st/3622/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        int i, ans;
        
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                s.insert(nums[i]);
            } else {
                s.insert(nums[i] * 2);
            }
        }
        
        ans = *s.rbegin() - *s.begin();
        while (true) {
            i = *s.rbegin();
            if (i % 2 == 1) {
                break;
            }
            s.erase(i);
            s.insert(i / 2);
            ans = min(ans, *s.rbegin() - *s.begin());
        }
        
        return ans;
    }
};
