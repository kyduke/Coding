// https://leetcode.com/problems/guess-number-higher-or-lower/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long left, right, step, result;
        
        left = 1;
        right = n;
        
        while (left < right) {
            step = (right - left) / 10;
            if (step == 0) step = 1;
            while (left <= right) {
                result = guess(left);
                if (result == 0) {
                    return left;
                } else if (result == -1) {
                    right = left;
                    left = left - step + 1;
                    break;
                }
                left += step;
                if (left > right) left = right;
            }
        }
        
        return left;
    }
};
