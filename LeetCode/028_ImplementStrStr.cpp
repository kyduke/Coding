// https://leetcode.com/problems/implement-strstr/#/description

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i, j;
        bool flag;
        
        if (needle.size() == 0) return 0;
        
        for (i = 0; i <= (int)haystack.size() - (int)needle.size(); i++) {
            flag = true;
            for (j = 0; j < needle.size(); j++) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return i;
        }
        
        return -1;
    }
};
