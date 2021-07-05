// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3801/
// 39 / 39 test cases passed, but took too long. TLE

// Solution: https://www.geeksforgeeks.org/maximum-sum-not-exceeding-k-possible-for-any-rectangle-of-a-matrix/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        vector<int> arr;
        vector<vector<int>> sum;
        int ans, w, h, i, j, a, b, temp;
        
        w = matrix[0].size();
        h = matrix.size();
        arr.assign(w + 1, 0);
        sum.assign(h + 1, arr);
        
        for (i = 1; i <= h; i++) {
            for (j = 1; j <= w; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        
        ans = -1000000000;
        for (a = 1; a <= h; a++) {
            for (b = 1; b <= w; b++) {
                for (i = a; i <= h; i++) {
                    for (j = b; j <= w; j++) {
                        temp = sum[i][j] - sum[a - 1][j] - sum[i][b - 1] + sum[a - 1][b - 1];
                        if (temp <= k && temp > ans) {
                            ans = temp;
                            if (temp == k) {
                                return temp;
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
