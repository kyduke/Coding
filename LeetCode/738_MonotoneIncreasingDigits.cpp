// https://leetcode.com/problems/monotone-increasing-digits/description/

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> arr;
        int i, k, ans;
        
        k = N;
        while (k) {
            arr.push_back(k % 10);
            k /= 10;
        }
        
        for (k = arr.size() - 2; k >= 0; k--) {
            if (arr[k] < arr[k + 1]) {
                for (i = 0; i < k; i++) {
                    arr[i] = 9;
                }
                for (i = k + 1; i < arr.size(); i++) {
                    if (arr[i] > arr[i - 1]) {
                        arr[i - 1] = 9;
                        arr[i]--;
                    }
                }
            }
        }
        
        ans = 0;
        for (i = arr.size() - 1; i >= 0; i--) {
            ans = ans * 10 + arr[i];
        }
        
        return ans;
    }
};

/*
10
=====
9

1234
=====
1234

332
=====
299
*/
