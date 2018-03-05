// https://leetcode.com/contest/weekly-contest-74/problems/preimage-size-of-factorial-zeroes-function/

class Solution {
public:
    int preimageSizeFZF(int k) {
        unsigned long long l, r, m, d, temp;

        l = 0;
        r = 100000000000;
        while (l < r) {
            m = (l + r) / 2;
            d = 5;
            temp = 0;
            while (d <= m) {
                temp += m / d;
                d *= 5;
            }
            if (k < temp) {
                r = m;
            } else {
                if (l == m) break;
                l = m;
            }
        }

        if (k == temp) return 5;

        return 0;
    }
};
