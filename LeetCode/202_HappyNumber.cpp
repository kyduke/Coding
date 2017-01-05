// https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        int t, d;
        bool one;
        
        if (n <= 0) return false;
        
        one = false;
        s.insert(n);
        while (n != 1) {
            t = 0;
            while (n) {
                d = n % 10;
                if (d == 1) one = true;
                t += d * d;
                n /= 10;
            }
            n = t;
            if (s.find(n) != s.end()) {
                return !one;
            }
            s.insert(n);
        }
        
        return true;
    }
};
