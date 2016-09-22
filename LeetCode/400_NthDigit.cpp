// https://leetcode.com/problems/nth-digit/

class Solution {
public:
    int findNthDigit(int n) {
        vector<int> arr;
        int i, len, limit, m;
        
        i = 0;
        len = 1;
        limit = 9;
        while (n >= len) {
            m = min(limit, n / len);
            i += m;
            n -= m * len;
            len++;
            limit *= 10;
        }
        
        if (n == 0) {
            return i % 10;
        }
        
        i++;
        while (i) {
            arr.push_back(i % 10);
            i /= 10;
        }
        reverse(arr.begin(), arr.end());
        
        return arr[n - 1];
    }
};
