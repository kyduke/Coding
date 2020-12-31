// https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/573/week-5-december-29th-december-31st/3587/

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        vector<int> left, right;
        int i, j, n, ans;
        
        n = arr.size();
        left.assign(n, -1);
        right.assign(n, n);
        
        for (i = 0; i < n; i++) {
            j = i - 1;
            while(j >= 0 && arr[j] >= arr[i]) {
                j = left[j];
            }
            left[i] = j;
        }
        
        for (i = n - 1; i >= 0; i--) {
            j = i + 1;
            while(j < n && arr[j] >= arr[i]) {
                j = right[j];
            }
            right[i] = j;
        }
        
        ans = 0;
        for (i = 0; i < n; i++) {
            ans = max(ans, (right[i] - left[i] - 1) * arr[i]);
        }
        
        return ans;
    }
};
