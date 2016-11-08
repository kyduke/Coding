// https://leetcode.com/problems/number-of-boomerangs/

class Solution {
private:
    int dist(pair<int, int>& a, pair<int, int>& b) {
        int x, y;
        
        x = a.first - b.first;
        y = a.second - b.second;
        return x * x + y * y;
    }
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        map<int, int> m;
        map<int, int>::iterator it;
        int i, j, d, ans;
        
        ans = 0;
        for (i = 0; i < points.size(); i++) {
            m.clear();
            for (j = 0; j < points.size(); j++) {
                if (i == j) continue;
                d = dist(points[i], points[j]);
                m[d]++;
            }
            for (it = m.begin(); it != m.end(); it++) {
                ans += it->second * (it->second - 1);
            }
        }
        
        return ans;
    }
};
