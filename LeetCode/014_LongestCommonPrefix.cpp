// https://leetcode.com/problems/longest-common-prefix/#/description

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        char c;
        int i, j, minLen;
        
        ans = "";
        
        if (strs.size() == 0) return ans;
        
        minLen = strs[0].size();
        for (i = 1; i < strs.size(); i++) {
            minLen = min(minLen, (int)strs[i].size());
        }
        
        for (i = 0; i < minLen; i++) {
            c = strs[0][i];
            for (j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) {
                    return ans;
                }
            }
            ans += c;
        }
        
        return ans;
    }
};
