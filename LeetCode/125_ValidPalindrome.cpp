// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        int i, left, right;
        string str;
        
        str = "";
        for (i = 0; i < s.size(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                str += s[i];
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                str += s[i] - 'A' + 'a';
            }
        }
        
        left = 0;
        right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) return false;
            left++;
            right--;
        }
        
        return true;
    }
};
