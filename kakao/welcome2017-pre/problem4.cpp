// https://www.welcomekakao.com/tryouts/1467/challenges/3529?language=cpp

#include<vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    int ans, i, j, k, s, row, col;
    vector<vector<int>> sum;
    vector<int> arr;
    
    row = board.size();
    if (row == 0) return 0;
    col = board[0].size();
    if (col == 0) return 0;
    
    arr.assign(col + 1, 0);
    for (i = 0; i < row + 1; i++) {
        sum.push_back(arr);
    }
    
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + board[i][j];
        }
    }
    
    for (i = 2; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            sum[i][j] += sum[i - 1][j];
        }
    }
    
    ans = 0;
    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            if (board[i - 1][j - 1] == 0) continue;
            if (ans == 0) ans = 1;
            k = ans;
            while (i + k  <= row && j + k <= col) {
                if (board[i + k - 1][j + k - 1] == 0) break;
                s = sum[i + k][j + k] - sum[i + k][j - 1] - sum[i - 1][j + k] + sum[i - 1][j - 1];
                k++;
                if (s != k * k) break;
                ans++;
            }
        }
    }
    
    return ans * ans;
}

/*
1와 0로 채워진 표(board)가 있습니다. 표 1칸은 1 x 1 의 정사각형으로 이루어져 있습니다. 표에서 1로 이루어진 가장 큰 정사각형을 찾아 넓이를 return 하는 solution 함수를 완성해 주세요. (단, 정사각형이란 축에 평행한 정사각형을 말합니다.)

예를 들어

1	2	3	4
0	1	1	1
1	1	1	1
1	1	1	1
0	0	1	0
가 있다면 가장 큰 정사각형은

1	2	3	4
0	1	1	1
1	1	1	1
1	1	1	1
0	0	1	0
가 되며 넓이는 9가 되므로 9를 반환해 주면 됩니다.

제한사항
표(board)는 2차원 배열로 주어집니다.
표(board)의 행(row)의 크기 : 1000 이하의 자연수
표(board)의 열(column)의 크기 : 1000 이하의 자연수
표(board)의 값은 1또는 0으로만 이루어져 있습니다.
시간제한 : 87ms
입출력 예
board	answer
[[0,1,1,1],[1,1,1,1],[1,1,1,1],[0,0,1,0]]	9
[[0,0,1,1],[1,1,1,1]]	4
입출력 예 설명
입출력 예 #1
위의 예시와 같습니다.

입출력 예 #2
| 0 | 0 | 1 | 1 |
| 1 | 1 | 1 | 1 | 
로 가장 큰 정사각형의 넓이는 4가 되므로 4를 return합니다.
*/
