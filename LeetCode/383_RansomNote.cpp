// https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int alphabet[26] = {0, };
        int i;
        
        for (i = 0; i < ransomNote.size(); i++) {
            alphabet[ransomNote[i] - 'a']++;
        }
        
        for (i = 0; i < magazine.size(); i++) {
            alphabet[magazine[i] - 'a']--;
        }
        
        for (i = 0; i < 26; i++) {
            if (alphabet[i] > 0) return false;
        }
        
        return true;
    }
};

/*
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
