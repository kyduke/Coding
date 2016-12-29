// https://leetcode.com/problems/4sum-ii/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> x;
        map<int, int>::iterator it;
        int ans, i, j, t, l;
        
        ans = 0;
        l = A.size();
        for (i = 0; i < l; i++) {
            for (j = 0; j < l; j++) {
                t = A[i] + B[j];
                it = x.find(t);
                if (it == x.end()) {
                    x[t] = 1;
                } else {
                    it->second++;
                }
            }
        }
        
        for (i = 0; i < l; i++) {
            for (j = 0; j < l; j++) {
                t = C[i] + D[j];
                it = x.find(-t);
                if (it != x.end()) ans += it->second;
            }
        }
        
        return ans;
    }
};
