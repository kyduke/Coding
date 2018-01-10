// https://leetcode.com/problems/find-anagram-mappings/

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int i, len;
        
        len = A.size();
        ans.assign(len, 0);
        for (i = 0; i < len; i++) {
            A[i] = A[i] * 1000 + i;
            B[i] = B[i] * 1000 + i;
        }
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        for (i = 0; i < len; i++) {
            ans[A[i] % 1000] = B[i] % 1000;
        }
        
        return ans;
    }
};

/*
[12, 28, 46, 32, 50]
[50, 12, 32, 46, 28]
=====
[1, 4, 3, 2, 0]
*/
