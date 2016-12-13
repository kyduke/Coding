// https://leetcode.com/problems/number-of-segments-in-a-string/

class Solution {
public:
    int countSegments(string s) {
        int i, ans;
        bool flag;
        
        ans = 0;
        
        flag = false;
        for (i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                flag = true;
                break;
            }
        }
        
        if (!flag) return ans;
        
        ans++;
        
        for (; i < s.size() - 1; i++) {
            if (s[i] == ' ' && s[i + 1] != ' ') ans++;
        }
        
        return ans;
    }
};

/*
"Hello, my name is John"
=====
5
*/
