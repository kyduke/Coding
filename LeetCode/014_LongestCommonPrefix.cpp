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

// 2018-01-04 fastre solution
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int i, j;
        
        if (strs.size() == 0) return ans;
        
        ans = strs[0];
        for (i = 1; i < strs.size(); i++) {
            for (j = 0; j < min(ans.size(), strs[i].size()); j++) {
                if (ans[j] != strs[i][j]) break;
            }
            ans = ans.substr(0, min((int)ans.size(), j));
        }
        
        return ans;
    }
};
