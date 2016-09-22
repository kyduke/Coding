// https://leetcode.com/problems/integer-replacement/

class Solution {
public:
    int integerReplacement(int n) {
        queue<pair<int, int>> q;
        int ans, m, c;
        
        ans = 2147483647;
        
        if (n == 2147483647) {
            q.push(make_pair(1073741824, 2));
        } else {
            q.push(make_pair(n, 0));
        }
        
        while (!q.empty()) {
            m = q.front().first;
            c = q.front().second;
            q.pop();
            if (m == 1) {
                ans = min(ans, c);
                continue;
            }
            if (m % 2 == 0) {
                q.push(make_pair(m / 2, c + 1));
            } else {
                q.push(make_pair((m - 1) / 2, c + 2));
                q.push(make_pair((m + 1) / 2, c + 2));
            }
        }
        
        return ans;
    }
};
