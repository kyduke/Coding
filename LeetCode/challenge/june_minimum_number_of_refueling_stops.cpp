// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/604/week-2-june-8th-june-14th/3776/

typedef long long INT64;

class Solution {
public:
    int minRefuelStopsN2(int target, int startFuel, vector<vector<int>>& stations) {
        INT64 dp[502][502] = {0, };
        int i, j, n;
        
        n = stations.size();
        for (i = 0; i < n + 1; i++) {
            for (j = 0; j <= i; j++) {
                dp[i][j] = -1;
            }
        }
        
        dp[0][1] = startFuel;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= i + 1; j++) {
                if (dp[i - 1][j - 1] >= stations[i - 1][0]) {
                    dp[i][j] = dp[i - 1][j - 1] + stations[i - 1][1];
                }
                if (dp[i - 1][j] >= stations[i - 1][0]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }
            }
        }
        
        for (i = 1; i < n + 2; i++) {
            if (dp[n][i] >= target) {
                return i - 1;
            }
        }
        
        return -1;
    }
    
    int minRefuelStopsNLogN(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> q;
        int i, n, ans;
        
        i = 0;
        n = stations.size();
        ans = 0;
        while (startFuel < target) {
            while (i < n && stations[i][0] <= startFuel) {
                q.push(stations[i][1]);
                i++;
            }
            if (q.empty()) {
                return -1;
            }
            startFuel += q.top();
            q.pop();
            ans++;
        }
        
        return ans;
    }
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        return minRefuelStopsNLogN(target, startFuel, stations);
    }
};

/*
1
1
[]
==========
0

100
1
[[10,100]]
==========
-1

100
10
[[10,60],[20,30],[30,30],[60,40]]
==========
2
*/
