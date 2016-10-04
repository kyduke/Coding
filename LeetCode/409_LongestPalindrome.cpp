// https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        map<char, int>::iterator it;
        int i, ans;
        
        ans = 0;
        for (i = 0; i < s.size(); i++) {
            m[ s[i] ]++;
        }
        
        for (it = m.begin(); it != m.end(); it++) {
            ans += (it->second / 2) * 2;
        }
        
        if (ans != s.size()) ans++;
        
        return ans;
    }
};
