// https://leetcode.com/problems/arithmetic-slices/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        long long c, d, t, ans;
        int i;
        
        ans = 0;
        c = 0;
        d = 0;
        for (i = 1; i < A.size(); i++) {
            t = A[i - 1] - A[i];
            if (d == t) {
                c++;
            } else {
                if (c > 1) {
                    ans += c * (c - 1) / 2;
                }
                d = t;
                c = 1;
            }
        }
        if (c > 1) {
            ans += c * (c - 1) / 2;
        }
        
        return ans;
    }
};
