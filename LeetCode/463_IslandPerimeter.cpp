// https://leetcode.com/problems/island-perimeter/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int i, j, w, h, ans;
        
        ans = 0;
        h = grid.size();
        if (h == 0) return ans;
        w = grid[0].size();
        if (w == 0) return ans;
        
        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                if (grid[i][j] == 0) continue;
                if (i == 0 || i > 0 && grid[i - 1][j] == 0) ans++;
                if (i == h - 1 || i < h - 1 && grid[i + 1][j] == 0) ans++;
                if (j == 0 || j > 0 && grid[i][j - 1] == 0) ans++;
                if (j == w - 1 || j < w - 1 && grid[i][j + 1] == 0) ans++;
            }
        }
        
        return ans;
    }
};
