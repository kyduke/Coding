// https://leetcode.com/problems/roman-to-integer/#/description

class Solution {
public:
    int romanToInt(string s) {
        char c;
        int ans, i;
        
        ans = 0;
        
        for (i = 0; i < s.size(); i++) {
            c = s[i];
            if (c == 'I') {
                if (i < s.size() - 1) {
                    if (s[i + 1] == 'V') {
                        ans += 4;
                        i++;
                        continue;
                    } else if (s[i + 1] == 'X') {
                        ans += 9;
                        i++;
                        continue;
                    }
                }
                ans++;
            } else if (c == 'V') {
                ans += 5;
            } else if (c == 'X') {
                if (i < s.size() - 1) {
                    if (s[i + 1] == 'L') {
                        ans += 40;
                        i++;
                        continue;
                    } else if (s[i + 1] == 'C') {
                        ans += 90;
                        i++;
                        continue;
                    }
                }
                ans += 10;
            } else if (c == 'L') {
                ans += 50;
            } else if (c == 'C') {
                if (i < s.size() - 1) {
                    if (s[i + 1] == 'D') {
                        ans += 400;
                        i++;
                        continue;
                    } else if (s[i + 1] == 'M') {
                        ans += 900;
                        i++;
                        continue;
                    }
                }
                ans += 100;
            } else if (c == 'D') {
                ans += 500;
            } else if (c == 'M') {
                ans += 1000;
            }
        }
        
        return ans;
    }
};
