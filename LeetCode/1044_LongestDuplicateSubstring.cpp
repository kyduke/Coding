// https://leetcode.com/problems/longest-duplicate-substring/
// Solution using KMP, it is TLE(Time Limit Excedded). I keep it to study KMP.

class Solution {
private:
    int fail[100001] = {0, };
    
    int preKMP(string& pattern) {
        int i, m, k, x;

        m = pattern.size();
        for (i = 1; i <= m; i++) {
            fail[i] = 0;
        }

        fail[0] = -1;
        for (i = 1; i < m; i++) {
            k = fail[i - 1];
            while (k >= 0) {
                if (pattern[k] == pattern[i - 1]) {
                    break;
                } else {
                    k = fail[k];
                }
            }
            fail[i] = k + 1;
        }
        
        x = 0;
        for (i = 0; i < m; i++) {
            x = max(x, fail[i]);
        }
        
        return x;
    }
public:
    string longestDupSubstring(string str) {
        string sub;
        int i, ans, x, y, temp;
        
        return str;
        
        x = 0;
        y = 0;
        ans = 0;
        for (i = 0; i < str.size(); i++) {
            if (str.size() - 1 <= ans) break;
            sub = str.substr(i, str.size() - i);
            sub.push_back(' ');
            temp = preKMP(sub);
            if (temp > ans) {
                ans = temp;
                x = i;
                y = ans;
            }
        }
        
        return str.substr(x, y);
    }
};
