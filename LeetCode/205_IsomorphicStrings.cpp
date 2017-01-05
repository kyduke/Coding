// https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int arr[256], brr[256];
        int i, j, k;
        
        for (i = 0; i < 256; i++) {
            arr[i] = -1;
            brr[i] = -1;
        }
        
        for (i = 0; i < s.size(); i++) {
            j = s[i];
            k = t[i];
            
            if (arr[j] != -1 && arr[j] != k) return false;
            if (brr[k] != -1 && brr[k] != j) return false;
            
            arr[j] = k;
            brr[k] = j;
        }
        
        return true;
    }
};
