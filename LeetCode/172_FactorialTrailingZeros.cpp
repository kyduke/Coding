// https://leetcode.com/problems/factorial-trailing-zeroes/

class Solution {
public:
    int trailingZeroes(int n) {
        int ans;
        long long i;
        
        ans = 0;
        i = 5;
        while(i <= n) {
            ans += n / i;
            i *= 5;
        }
        
        return ans;
    }
};
