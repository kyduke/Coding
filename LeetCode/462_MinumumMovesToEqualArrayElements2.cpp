// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        map<int, int> m;
        map<int, int>::iterator it;
        map<int, int>::reverse_iterator rit;
        int i, c, ans;
        
        ans = 0;
        
        for (i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        
        while (m.size() > 1) {
            it = m.begin();
            rit = m.rbegin();
            if (it->second < rit->second) {
                i = it->first;
                c = it->second;
                m.erase(it);
                it = m.begin();
                it->second += c;
                ans += (it->first - i) * c;
            } else {
                i = rit->first;
                c = rit->second;
                m.erase(next(rit).base());
                rit = m.rbegin();
                rit->second += c;
                ans += (i - rit->first) * c;
            }
        }
        
        return ans;
    }
};
