// https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int ss[26] = {0, };
        int i;
        
        for (i = 0; i < s.size(); i++) {
            ss[ s[i] - 'a' ]--;
            ss[ t[i] - 'a' ]++;
        }
        ss[ t[i] - 'a' ]++;
        
        for (i = 0; i <26; i++) {
            if (ss[i] == 1) {
                return 'a' + i;
            }
        }
        
        return 0;
    }
};
