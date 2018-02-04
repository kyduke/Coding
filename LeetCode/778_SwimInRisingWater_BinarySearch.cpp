// https://leetcode.com/problems/swim-in-rising-water/

class Solution {
private:
    int visitedIndex;
    int visited[2500];
    bool connectedWithNum(vector<vector<int>>& grid, int k) {
        queue<int> q;
        int i, j, n, x;
        
        visitedIndex++;
        n = grid.size();
        
        if (grid[0][0] > k) return false;
        
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
                if (grid[i - 1][j] <= k && visited[x] != visitedIndex) {
                    visited[x] = visitedIndex;
                    q.push(x);
                }
            }
            if (i < n - 1) {
                x = (i + 1) * n + j;
                if (grid[i + 1][j] <= k && visited[x] != visitedIndex) {
                    visited[x] = visitedIndex;
                    q.push(x);
                }
            }
            if (j > 0) {
                x = i * n + j - 1;
                if (grid[i][j - 1] <= k && visited[x] != visitedIndex) {
                    visited[x] = visitedIndex;
                    q.push(x);
                }
            }
            if (j < n - 1) {
                x = i * n + j + 1;
                if (grid[i][j + 1] <= k && visited[x] != visitedIndex) {
                    visited[x] = visitedIndex;
                    q.push(x);
                }
            }
        }
        
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int left, right, mid;
        
        visitedIndex = 0;
        memset(visited, 2500, 0);
        
        left = 0;
        right = grid.size() * grid.size() - 1;
        while (left < right) {
            mid = (left + right) / 2;
            if (connectedWithNum(grid, mid) == true) {
                right = mid;
            } else {
                if (left == mid) {
                    left++;
                } else {
                    left = mid;
                }
            }
        }
        
        return left;
    }
};
