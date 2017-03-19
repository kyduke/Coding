// https://leetcode.com/problems/count-and-say/#/description

class Solution {
private:
    string number2string(int n) {
        string ans;
        int d;
        
        ans = "";
        
        d = 10;
        while (d <= n) d *= 10;
        d /= 10;
        
        while (d) {
            ans += ((n / d) + '0');
            n %= d;
            d /= 10;
        }
        
        return ans;
    }
    string nextGen(string& str) {
        string ans;
        char p;
        int i, c;
        
        ans = "";
        p = str[0];
        c = 1;
        for (i = 1; i < str.size(); i++) {
            if (p == str[i]) {
                c++;
            } else {
                ans += number2string(c);
                ans += p;
                p = str[i];
                c = 1;
            }
        }
        ans += number2string(c);
        ans += p;
        
        return ans;
    }
public:
    string countAndSay(int n) {
        string ans;
        
        ans = "";
        if (n < 1) return ans;
        
        ans = "1";
        n--;
        while (n--) {
            ans = nextGen(ans);
        }
        
        return ans;
    }
};
