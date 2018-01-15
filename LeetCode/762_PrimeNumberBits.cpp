// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/

class Solution {
private:
    int bits[1000001] = {0, };
    int primes[32] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1};
    int countBits(int n) {
        int c;
        
        if (n == 0) return 0;
        
        while ((n & 1) == false) {
            n >>= 1;
        }
        if (bits[n] > 0) return bits[n];
        
        c = countBits(n >> 1) + 1;
        bits[n] = c;
        
        return c;
    }
public:
    int countPrimeSetBits(int L, int R) {
        map<int, int>::iterator it;
        int i, ans;
        
        ans = 0;
        for (i = L; i <= R; i++) {
            if (primes[countBits(i)] == 1) ans++;
        }
        
        return ans;
    }
};

/*
6 10
=====
4

Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)

10 15
=====
5

Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
*/
