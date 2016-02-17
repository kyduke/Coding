// https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<pair<int, int>> subs;
        vector<pair<int, int>> copy;
        int i, j, l, length;

        for (i = 0; i < nums.size(); i++) {
            l = subs.size();
            length = 0;
            for (j = 0; j < l; j++) {
                if (subs[j].second < nums[i]) {
                    if (length <= subs[j].first) length = subs[j].first + 1;
                }
            }
            if (length > 2) return true;
            if (length == 0) {
                subs.push_back(make_pair(1, nums[i]));
            } else {
                copy = subs;
                subs.clear();
                for (j = 0; j < copy.size(); j++) {
                    if (copy[j].first >= length || copy[j].second <= nums[i]) {
                        subs.push_back(copy[j]);
                    }
                }
                subs.push_back(make_pair(length, nums[i]));
                copy.clear();
            }
        }

        length = 0;
        for (i = 0; i < subs.size(); i++) {
            if (length < subs[i].first) length = subs[i].first;
        }

        return length > 2;
    }
};
