// https://leetcode.com/problems/binary-watch/

class Solution {
private:
    int b0 = 1;
    int b1 = 2;
    int b2 = 4;
    int b3 = 8;
    int b4 = 16;
    int b5 = 32;
    int b6 = 64;
    int b7 = 128;
    int b8 = 256;
    int b9 = 512;
    int bx = 1024;
    string num2str(int n) {
        string str;
        int i;
        
        str = "";
        
        i = n & 15;
        if (i > 11) {
            return "";
        } else if (i >= 10) {
            str +='1';
            str += ('0' + (i - 10));
        } else {
            str += ('0' + i);
        }
        str += ':';
        
        i = n >> 4;
        if (i > 59) {
            return "";
        } else {
            str += ('0' + (i / 10));
            str += ('0' + (i % 10));
        }
        
        return str;
    }
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        string str;
        int i, c;
        
        for (i = 0; i < bx; i++) {
            c = (i & b0) + ((i & b1) >> 1) + ((i & b2) >> 2) + ((i & b3) >> 3) + ((i & b4) >> 4) + ((i & b5) >> 5) + ((i & b6) >> 6) + ((i & b7) >> 7) + ((i & b8) >> 8) + ((i & b9) >> 9);
            if (c == num) {
                str = num2str(i);
                if (str.size() > 0) {
                    ans.push_back(str);
                }
            }
        }
        
        return ans;
    }
};
