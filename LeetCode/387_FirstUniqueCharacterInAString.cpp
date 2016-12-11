// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        int ss[26] = {0, };
        int i;
        
        for (i = 0; i < s.size(); i++) {
            ss[ s[i] - 'a' ]++;
        }
        
        for (i = 0; i < s.size(); i++) {
            if (ss[ s[i] - 'a' ] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};
