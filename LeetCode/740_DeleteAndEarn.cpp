// https://leetcode.com/problems/delete-and-earn/description/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> numAndCount;
        map<int, int>::iterator it, jt;
        vector<int> arr, sum;
        int i;
        
        for (i = 0; i < nums.size(); i++) {
            it = numAndCount.find(nums[i]);
            if (it == numAndCount.end()) {
                numAndCount.insert(make_pair(nums[i], nums[i]));
            } else {
                it->second += nums[i];
            }
        }
        
        arr.push_back(0);
        for (it = numAndCount.begin(); it != numAndCount.end(); it++) {
            arr.push_back(it->second);
            jt = it;
            jt++;
            if (jt == numAndCount.end() || it->first + 1 < jt->first) {
                arr.push_back(0);
            }
        }
        
        sum.assign(arr.size(), 0);
        
        sum[1] = arr[1];
        for (i = 2; i < arr.size() - 1; i++) {
            sum[i] = max(sum[i - 2] + arr[i], sum[i - 1]);
        }
        
        return sum[arr.size() - 2];
    }
};

/*
[3, 4, 2]
=====
6

[2, 2, 3, 3, 3, 4]
=====
9
*/
