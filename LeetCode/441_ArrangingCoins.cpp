// https://leetcode.com/problems/arranging-coins/

class Solution {
public:
    int arrangeCoins(int n) {
        long long left, right, mid, k;
        
        left = 0;
        k = n;
        right = (k + 1) / 2;
        while (left < right) {
            mid = (left + right) / 2;
            k = mid * (mid + 1) / 2;
            if (k > n) {
                right = mid;
            } else {
                if (left == mid) {
                    left = mid + 1;
                } else {
                    left = mid;
                }
            }
        }
        
        k = right * (right + 1) / 2;
        
        return k <= n ? right : right - 1;
    }
};
