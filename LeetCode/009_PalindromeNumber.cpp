// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        int n, y;
        
        if (x < 0) return false;
        
        n = x;
        y = 0;
        while (n) {
            y = y * 10 + (n % 10);
            n /= 10;
        }
        
        while (x) {
            if ((x % 10) != (y% 10)) return false;
            x /= 10;
            y /= 10;
        }
        
        return true;
    }
};
