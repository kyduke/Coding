// https://leetcode.com/problems/rectangle-area/

class Solution {
public:
    int computeArea(int a, int b, int c, int d, int e, int f, int g, int h) {
        int i, j, k, l, t, ans;
        
        if (a > c) {
            t = a;
            a = c;
            c = t;
        }
        
        if (b > d) {
            t = b;
            b = d;
            d = t;
        }
        
        if (e > g) {
            t = e;
            e = g;
            g = t;
        }
        
        if (f > h) {
            t = f;
            f = h;
            h = t;
        }
        
        i = max(a, e);
        j = max(b, f);
        k = min(c, g);
        l = min(d, h);
        
        ans = (c - a) * (d - b) + (g - e) * (h - f);
        if (k > i && l > j) {
            ans -= (k - i) * (l - j);
        }
        
        return ans;
    }
};
