// https://leetcode.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans, h;
        
        ans = 0;
        h = x ^ y;
        
        while (h) {
            if (h & 1) ans++;
            h >>= 1;
        }
        
        return ans;
    }
};

/*
1 4
=====
2
*/
