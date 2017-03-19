// https://leetcode.com/problems/reverse-integer/#/description

class Solution {
public:
    int reverse(int x) {
        long long ans;
        int sign;
        
        if (x == -2147483648) return 0;
        
        sign = 1;
        if (x < 0) {
            sign = -1;
            x *= -1;
        }
        
        ans = 0;
        while (x) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        
        if (ans > 2147483647) ans = 0;
        
        return ans * sign;
    }
};
