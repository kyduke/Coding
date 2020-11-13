// https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3528/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        findPU(nums, 0, result);
        return result;
    }
    
    
    void findPU(vector<int>& nums, int start, vector<vector<int>>& result){
        if(start == nums.size()){
            result.push_back(nums);
            return;
        }    
        
        int len = nums.size();
        for(int i=start; i<len; i++){
            int j = i - 1;
            while (j >= start && nums[j] != nums[i]) --j;
            if (j != start - 1) continue;
            
            swap(nums[start], nums[i]);
            findPU(nums, start+1, result);
            swap(nums[start], nums[i]);
        }
        
        return;
    }
};
