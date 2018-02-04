// https://leetcode.com/problems/swim-in-rising-water/description/

class Solution {
private:
    int visitedIndex;
    int visited[2500];
    int connectedLower[2500];
    bool connectedWithNum(vector<vector<int>>& grid, int k) {
        queue<int> q;
        int i, j, n, x;
        
        visitedIndex++;
        n = grid.size();
        
        q.push(0);
        visited[0] = visitedIndex;
        while (!q.empty()) {
            i = q.front();
            q.pop();
            j = i % n;
            i = i / n;
            
            if (i == n - 1 && j == n - 1) return true;
            
            if (i > 0) {
                x = (i - 1) * n + j;
                if (grid[i][j] <= k && visited[x] != visitedIndex) {
                    visited[x] = visitedIndex;
                    q.push(x);
                }
            }
            if (i < n - 1) {
                x = (i + 1) * n + j;
                if (grid[i][j] <= k && visited[x] != visitedIndex) {
                    visited[x] = visitedIndex;
                    q.push(x);
                }
            }
            if (j > 0) {
                x = i * n + j - 1;
                if (grid[i][j] <= k && visited[x] != visitedIndex) {
                    visited[x] = visitedIndex;
                    q.push(x);
                }
            }
            if (j < n - 1) {
                x = i * n + j + 1;
                if (grid[i][j] <= k && visited[x] != visitedIndex) {
                    visited[x] = visitedIndex;
                    q.push(x);
                }
            }
        }
        
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int i, j, k, n, ans;
        
        visitedIndex = 0;
        memset(visited, 2500, 0);
        memset(connectedLower, 2500, 0);
        
        n = grid.size();
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                k = grid[i][j];
                if (i > 0 && grid[i - 1][j] < k) {
                    connectedLower[k] = 1;
                    continue;
                } else if (i < n - 1 && grid[i + 1][j] < k) {
                    connectedLower[k] = 1;
                    continue;
                } else if (j > 0 && grid[i][j - 1] < k) {
                    connectedLower[k] = 1;
                    continue;
                } else if (j < n - 1 && grid[i][j + 1] < k) {
                    connectedLower[k] = 1;
                    continue;
                }
            }
        }
        
        ans = max(grid[0][0], grid[n - 1][n - 1]);
        for (i = 1; i < n - 1; i++) {
            k = 2500;
            for (j = 0; j < n; j++) {
                k = min(k, grid[i][j]);
            }
            ans = max(ans, k);
        }
        
        for (j = 1; j < n - 1; j++) {
            k = 2500;
            for (i = 0; i < n; i++) {
                k = min(k, grid[i][j]);
            }
            ans = max(ans, k);
        }
        
        while (true) {
            if (connectedWithNum(grid, ans) == true) {
                break;
            }
            for (i = ans + 1; i < n * n; i++) {
                if (connectedLower[i] == 1) {
                    ans = i;
                    break;
                }
            }
        }
        
        return ans;
    }
};
