// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
private:
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int i, x, ans;
        
        if (points.size() == 0) {
            return 0;
        }
        
        sort(points.begin(), points.end(), comp);
        
        ans = 1;
        x = points[0].second;
        for (i = 1; i < points.size(); i++) {
            if (points[i].first <= x) {
                continue;
            }
            x = points[i].second;
            ans++;
        }
        
        return ans;
    }
};
