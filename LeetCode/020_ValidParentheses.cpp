// https://leetcode.com/problems/valid-parentheses/#/description

class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        char p;
        int i;
        
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                q.push(s[i]);
            } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (q.size() == 0) return false;
                p = q.top();
                if (p == '(' && s[i] != ')') {
                    return false;
                }
                if (p == '[' && s[i] != ']') {
                    return false;
                }
                if (p == '{' && s[i] != '}') {
                    return false;
                }
                q.pop();
            }
        }
        
        if (q.size() == 0) return true;
        
        return false;
    }
};
