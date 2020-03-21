//
//  main.cpp
//  ballpuzzle
//
//  Created by Guest User on 2020/03/21.
//  Copyright © 2020 Guest User. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

typedef unsigned long long UINT64;

set<UINT64> s;
int board[7][7] = {0, };

void init() {
    int i, j;
    
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            if ((i >= 2 && i <= 4) || (j >= 2 && j <= 4)) {
                board[i][j] = 1;
            } else {
                board[i][j] = 2;
            }
        }
    }
    board[3][3] = 0;
}

void printBoard(int r, int c) {
    int i, j;
    
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            if (board[i][j] == 2) {
                cout << "#";
            } else if (board[i][j] == 1) {
                if (i == r && j == c) {
                    cout << "x";
                } else {
                    cout << "o";
                }
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

UINT64 getId() {
    UINT64 id, temp;
    
    id = 0;
    
    temp = 0;
    if (board[0][2] == 1) temp += 1;
    if (board[0][3] == 1) temp += 2;
    if (board[0][4] == 1) temp += 4;
    if (board[1][2] == 1) temp += 8;
    if (board[1][3] == 1) temp += 16;
    if (board[1][4] == 1) temp += 32;
    id = temp;
    
    temp = 0;
    if (board[2][0] == 1) temp += 1;
    if (board[2][1] == 1) temp += 2;
    if (board[2][2] == 1) temp += 4;
    if (board[2][3] == 1) temp += 8;
    if (board[2][4] == 1) temp += 16;
    if (board[2][5] == 1) temp += 32;
    if (board[2][6] == 1) temp += 64;
    id = id * 1000 + temp;
    
    temp = 0;
    if (board[3][0] == 1) temp += 1;
    if (board[3][1] == 1) temp += 2;
    if (board[3][2] == 1) temp += 4;
    if (board[3][3] == 1) temp += 8;
    if (board[3][4] == 1) temp += 16;
    if (board[3][5] == 1) temp += 32;
    if (board[3][6] == 1) temp += 64;
    id = id * 1000 + temp;
    
    temp = 0;
    if (board[4][0] == 1) temp += 1;
    if (board[4][1] == 1) temp += 2;
    if (board[4][2] == 1) temp += 4;
    if (board[4][3] == 1) temp += 8;
    if (board[4][4] == 1) temp += 16;
    if (board[4][5] == 1) temp += 32;
    if (board[4][6] == 1) temp += 64;
    id = id * 1000 + temp;
    
    temp = 0;
    if (board[5][2] == 1) temp += 1;
    if (board[5][3] == 1) temp += 2;
    if (board[5][4] == 1) temp += 4;
    if (board[6][2] == 1) temp += 8;
    if (board[6][3] == 1) temp += 16;
    if (board[6][4] == 1) temp += 32;
    id = id * 1000 + temp;
    
    return id;
}

bool solve() {
    UINT64 id;
    int i, j, c;
    bool result;
    
    id = getId();
    if (s.find(id) != s.end()) return false;
    s.insert(id);
    
    c = 0;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            if (board[i][j] == 1) c++;
        }
    }
    
    if (c == 1) {
        printBoard(0, 0);
        return true;
    }
    
    for (i = 0; i < 7; i++) {
        for (j = 1; j < 6; j++) {
            if (board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 1) {
                board[i][j - 1] = 1;
                board[i][j] = 0;
                board[i][j + 1] = 0;
                result = solve();
                board[i][j - 1] = 0;
                board[i][j] = 1;
                board[i][j + 1] = 1;
                if (result == true) {
                    printBoard(i, j + 1);
                    return true;
                }
            }
            if (board[i][j - 1] == 1 && board[i][j] == 1 && board[i][j + 1] == 0) {
                board[i][j - 1] = 0;
                board[i][j] = 0;
                board[i][j + 1] = 1;
                result = solve();
                board[i][j - 1] = 1;
                board[i][j] = 1;
                board[i][j + 1] = 0;
                if (result == true) {
                    printBoard(i, j - 1);
                    return true;
                }
            }
        }
    }
    
    for (i = 1; i < 6; i++) {
        for (j = 0; j < 7; j++) {
            if (board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 1) {
                board[i - 1][j] = 1;
                board[i][j] = 0;
                board[i + 1][j] = 0;
                result = solve();
                board[i - 1][j] = 0;
                board[i][j] = 1;
                board[i + 1][j] = 1;
                if (result == true) {
                    printBoard(i + 1, j);
                    return true;
                }
            }
            if (board[i - 1][j] == 1 && board[i][j] == 1 && board[i + 1][j] == 0) {
                board[i - 1][j] = 0;
                board[i][j] = 0;
                board[i + 1][j] = 1;
                result = solve();
                board[i - 1][j] = 1;
                board[i][j] = 1;
                board[i + 1][j] = 0;
                if (result == true) {
                    printBoard(i - 1, j);
                    return true;
                }
            }
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    init();
    solve();
    
    return 0;
}
