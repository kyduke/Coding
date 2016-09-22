// https://leetcode.com/problems/rotate-function/

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int ans, sum, temp, i, l;
        
        l = A.size();
        ans = 0;
        sum = 0;
        for (i = 0; i < l; i++) {
            ans += i * A[i];
            sum += A[i];
        }
        
        temp = ans;
        for (i = l - 1; i > 0; i--) {
            temp = temp + sum - A[i] * l;
            ans = max(ans, temp);
        }
        
        return ans;
    }
};
