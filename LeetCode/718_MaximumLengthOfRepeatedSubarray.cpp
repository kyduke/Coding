// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

class Solution {
private:
    vector<int> fail;
    void preKMP(vector<int>& pattern) {
        int i, m, k;
        
        m = pattern.size();
        fail.clear();
        fail.assign(m + 1, 0);

        fail[0] = -1;
        for (i = 1; i <= m; i++) {
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
    int KMP(vector<int>& pattern, vector<int>& target) {
        int m, n, i, k, ans;
        
        m = pattern.size();
        n = target.size();
        i = 0;
        k = 0;
        ans = 0;
        while (i < n) {
            if (k == -1) {
                i++;
                k = 0;
            } else if (target[i] == pattern[k]) {
                i++;
                k++;
                ans = max(ans, k);
                if (k == m) break;
            } else {
                k = fail[k];
                if (k >= m) cout << k << "  ";
            }
        }
        
        return ans;
    }
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<int> copy;
        int ans;
        
        copy = A;
        ans = 0;
        while (copy.size() > 0) {
            preKMP(copy);
            ans = max(ans, KMP(copy, B));
            copy.erase(copy.begin());
        }
        
        return ans;
    }
};
