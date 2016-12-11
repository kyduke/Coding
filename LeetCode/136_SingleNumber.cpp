// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer, i;
        
        answer = 0;
        for (i = 0; i < nums.size(); i++) {
            answer ^= nums[i];
        }
        
        return answer;
    }
};
