// https://leetcode.com/problems/repeated-substring-pattern/

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int counts[26] = {0, };
        string patt, temp;
        int i, j, k, z;
        bool flag;
        
        z = str.size();
        
        for (i = 0; i < str.size(); i++) {
            counts [str[i] - 'a']++;
        }
        
        for (i = 2; i <= z; i++) {
            flag = true;
            for (j = 0; j < 26; j++) {
                if (counts[j] % i) {
                    flag = false;
                    break;
                }
            }
            if (flag == false) continue;
            k = z / i;
            patt = str.substr(0, k);
            temp = "";
            for (j = 0; j < i; j++) {
                temp += patt;
            }
            if (str == temp) {
                return true;
            }
        }
        
        return false;
    }
};
