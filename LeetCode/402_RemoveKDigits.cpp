// https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        stack<char> stk;
        
        for (char c : num) {
            while (!stk.empty() && k > 0 && stk.top() > c) {
                stk.pop();
                k -= 1;
            }

            if (!stk.empty() || c != '0') {
                stk.push(c);
            }
        }
        
        while (!stk.empty() && k--) {
            stk.pop();
        }
        
        if (stk.empty()) {
            return "0";
        }
        
        ans = "";
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
