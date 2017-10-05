// https://leetcode.com/problems/repeated-string-match/description/

class Solution {
private:
    vector<int> fail;
    void preKMP(string& pattern) {
        int i, m, k;
        
        m = pattern.size();
        fail.clear();
        fail.assign(m, 0);

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
    }
    bool KMP(string pattern, string target, int s) {
        int m, n, i, k;
        
        m = pattern.length();
        n = target.length();
        i = s;
        k = 0;
        while (i < n) {
            if (k == -1) {
                i++;
                k = 0;
            } else if (target[i] == pattern[k]) {
                i++;
                k++;
                if (k == m)
                    return true;
            } else {
                k = fail[k];
            }
        }
        
        return false;
    }
public:
    int repeatedStringMatch(string A, string B) {
        string str;
        int ans, k;
        
        preKMP(B);
        
        ans = 0;
        str = "";
        k = 0;
        while (true) {
            ans++;
            str += A;
            if (KMP(B, str, k) == true) return ans;
            k = str.size() - B.size();
            if (k < 0) k = 0;
            if (str.size() >= B.size() * 2) break;
        }
        
        return -1;
    }
};
