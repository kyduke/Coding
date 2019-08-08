// https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int cache[1001][1001] = {0, };
        int i, j;
        
        for (i = 0; i < text1.size(); i++) {
            for (j = 0; j < text2.size(); j++) {
                if (text1[i] == text2[j]) {
                    cache[i + 1][j + 1] = cache[i][j] + 1;
                } else {
                    cache[i + 1][j + 1] = max(cache[i + 1][j], cache[i][j + 1]);
                }
            }
        }
        
        return cache[text1.size()][text2.size()];
    }
};

/*
Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/
