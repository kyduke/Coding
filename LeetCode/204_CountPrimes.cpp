// https://leetcode.com/problems/count-primes/

class Solution {
public:
    int countPrimes(int n) {
        int* arr = new int[n + 2];
        int i, j, ans;
        
        for (i = 2; i < n; i++) arr[i] = 0;
        
        for (i = 2; i * i < n; i++) {
            if (arr[i] == 1) continue;
            for (j = i + i; j < n; j += i) {
                arr[j] = 1;
            }
        }
        
        ans = 0;
        for (i = 2; i < n; i++) {
            if (arr[i] == 0) ans++;
        }
        
        return ans;
    }
};
