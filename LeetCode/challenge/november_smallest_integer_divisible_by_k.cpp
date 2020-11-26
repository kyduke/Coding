// https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3543/

// My solution
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        vector<unsigned long long> arr;
        int i, j;
        unsigned long long n;
        
        if (k % 2 == 0 || k % 5 == 0) return -1;
        
        arr.push_back(0);
        i = 0;
        while (i < arr.size()) {
            if (arr[i] >= 10) {
                if (i + 1 == arr.size()) {
                    arr.push_back(0);
                }
                arr[i + 1] += arr[i] / 10;
                arr[i] %= 10;
            }
            if (arr[i] != 1) {
                for (j = 1; j < 10; j++) {
                    n = arr[i] + (unsigned long long)k * (unsigned long long)j;
                    if (n % 10 == 1) {
                        arr[i] = n;
                        break;
                    }
                }   
                continue;
            }
            i++;
        }
        
        return arr.size();
    }
};

// Best solution
class Solution {
public:
    int smallestRepunitDivByK(int K) {
      int rm=0;
        
      for (int N = 1; N <= K; ++N)
            if ( (rm = (rm * 10 + 1) % K) == 0)
                return N;
        return -1;
    }
};
