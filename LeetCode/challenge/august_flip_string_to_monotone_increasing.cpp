// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3876/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans, a, b, i;
        char p;
        
        s += '1';
        ans = 0;
        a = 0;
        b = 0;
        i = 0;
        while (i < s.size() && s[i] == '0') {
            i++;
        }
        p = s[i];
        while (i < s.size()) {
            if (p != s[i]) {
                if (p == '0' && a > b) {
                    ans += b;
                    a = 0;
                    b = 0;
                }
            }
            if (s[i] == '0') {
                a++;
            } else {
                b++;
            }
            p = s[i];
            i++;
        }
        ans += a;
        
        return ans;
    }
};
