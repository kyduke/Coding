// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ps[26] = {0, };
        int ss[20101][26] = {0, };
        int i, j, k;
        bool flag;
        vector<int> ans;
        
        for (i = 0; i < p.size(); i++) {
            ps[p[i] - 'a']++;
        }
        
        for (i = 1; i <= s.size(); i++) {
            for (j = 0; j < 26; j++) {
                ss[i][j] = ss[i - 1][j];
            }
            ss[i][s[i - 1] - 'a']++;
        }
        
        k = p.size();
        for (i = k; i <= s.size(); i++) {
            flag = true;
            for (j = 0; j < 26; j++) {
                if (ss[i][j] - ss[i - k][j] != ps[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans.push_back(i - k);
            }
        }
        
        return ans;
    }
};
