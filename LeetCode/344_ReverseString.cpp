class Solution {
public:
    string reverseString(string s) {
        string ret;
        char temp;
        int left, right;
        
        ret = s;
        left = 0;
        right = s.size() - 1;
        while (left < right) {
            temp = ret[left];
            ret[left] = ret[right];
            ret[right] = temp;
        
            left++;
            right--;
        }
        
        return ret;
    }
};
