// https://leetcode.com/problems/heaters/

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        vector<int> rads;
        int i, j, d, ans;
        
        ans = 0;
        
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        rads.assign(houses.size(), -1);
        
        j = 0;
        for (i = 0; i < houses.size(); i++) {
            d = houses[i] - heaters[j];
            if (d < 0) d = -d;
            rads[i] = d;
            while (j < heaters.size() - 1) {
                if (heaters[j] == heaters[j + 1]) {
                    j++;
                    continue;
                }
                d = houses[i] - heaters[j + 1];
                if (d < 0) d = -d;
                if (rads[i] < d) break;
                rads[i] = d;
                j++;
            }
        }
        
        for (i = 0; i < rads.size(); i++) {
            if (ans < rads[i]) ans = rads[i];
        }
        
        return ans;
    }
};

/*
[1, 2, 3], [2]
=====
1
*/
