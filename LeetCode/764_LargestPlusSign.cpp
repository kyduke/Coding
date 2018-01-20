// https://leetcode.com/problems/largest-plus-sign/

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> board1, board2, board3, board4, board5;
        vector<int> arr;
        int i, j, x, y, ans;
        
        arr.assign(N, 1);
        board1.assign(N, arr);
        
        arr.assign(N, 1000);
        board5.assign(N, arr);
        
        for (i = 0; i < mines.size(); i++) {
            x = mines[i][0];
            y = mines[i][1];
            board1[x][y] = 0;
            board5[x][y] = 0;
        }
        
        board2 = board1;
        board3 = board1;
        board4 = board1;
        
        for (i = 1; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (board1[i][j] == 0) continue;
                board1[i][j] = board1[i - 1][j] + 1;
                board5[i][j] = min(board5[i][j], board1[i][j]);
            }
        }
        
        for (i = N - 2; i >= 0; i--) {
            for (j = 0; j < N; j++) {
                if (board2[i][j] == 0) continue;
                board2[i][j] = board2[i + 1][j] + 1;
                board5[i][j] = min(board5[i][j], board2[i][j]);
            }
        }
        
        for (j = 1; j < N; j++) {
            for (i = 0; i < N; i++) {
                if (board3[i][j] == 0) continue;
                board3[i][j] = board3[i][j - 1] + 1;
                board5[i][j] = min(board5[i][j], board3[i][j]);
            }
        }
        
        for (j = N - 2; j >= 0; j--) {
            for (i = 0; i < N; i++) {
                if (board4[i][j] == 0) continue;
                board4[i][j] = board4[i][j + 1] + 1;
                board5[i][j] = min(board5[i][j], board4[i][j]);
            }
        }
        
        i = 0;
        for (j = 0; j < N; j++) {
            board5[i][j] = min(board5[i][j], board1[i][j]);
        }
        
        i = N - 1;
        for (j = 0; j < N; j++) {
            board5[i][j] = min(board5[i][j], board2[i][j]);
        }
        
        j = 0;
        for (i = 0; i < N; i++) {
            board5[i][j] = min(board5[i][j], board3[i][j]);
        }
        
        j = N - 1;
        for (i = 0; i < N; i++) {
            board5[i][j] = min(board5[i][j], board4[i][j]);
        }
        
        ans = 0;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                ans = max(ans, board5[i][j]);
                //cout << board5[i][j] << " ";
            }
            //cout << "\n";
        }
        
        return ans;
    }
};

/*
Input: N = 5, mines = [[4, 2]]
Output: 2
Explanation:
11111
11111
11111
11111
11011

Input: N = 2, mines = []
Output: 1

Input: N = 1, mines = [[0, 0]]
Output: 0
*/

