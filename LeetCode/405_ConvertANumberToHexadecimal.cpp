// https://leetcode.com/problems/convert-a-number-to-hexadecimal/

class Solution {
public:
    string toHex(int num) {
        long long n;
        string ans;
        
        ans = "";
        
        n = num;
        if (num < 0) {
            n = 4294967296 + num;
        }
        
        while (n) {
            num = n % 16;
            if (num < 10) {
                ans += '0' + num;
            } else{
                ans += 'a' + (num - 10);
            }
            n /= 16;
        }
        
        if (ans.size() == 0) {
            ans += "0";
        } else {
            reverse(ans.begin(), ans.end());
        }
        
        return ans;
    }
};
