//
//  main.cpp
//  AlgoSpot_KAKURO1
//
//  Created by Youngduke Koh on 10/11/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//
// https://algospot.com/judge/problem/read/KAKURO1

#include <iostream>

using namespace std;

const int SIZE = 20;

int map[SIZE][SIZE];
int hints[SIZE * SIZE][4];
int N, Q;

void solve() {
    int i, j, k, sum;
    
    cout << N << "\n";
    for (j = 0; j < N; j++) {
        for (i = 0; i < N; i++) {
            if (map[j][i] > 0) {
                cout << 1 << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
    
    for (j = 0; j < N; j++) {
        for (i = 0; i < N - 1; i++) {
            if (map[j][i] == 0 && map[j][i + 1] > 0) {
                hints[Q][0] = j + 1;
                hints[Q][1] = i + 1;
                hints[Q][2] = 0;
                sum = 0;
                for (i = i + 1; i < N; i++) {
                    if (map[j][i] == 0) break;
                    sum += map[j][i];
                }
                hints[Q][3] = sum;
                Q++;
                i--;
            }
        }
    }
    
    for (j = 0; j < N - 1; j++) {
        for (i = 0; i < N; i++) {
            if (map[j][i] == 0 && map[j + 1][i] > 0) {
                hints[Q][0] = j + 1;
                hints[Q][1] = i + 1;
                hints[Q][2] = 1;
                sum = 0;
                for (k = j + 1; k < N; k++) {
                    if (map[k][i] == 0) break;
                    sum += map[k][i];
                }
                hints[Q][3] = sum;
                Q++;
            }
        }
    }
    
    cout << Q << "\n";
    for (i = 0; i < Q; i++) {
        cout << hints[i][0] << " ";
        cout << hints[i][1] << " ";
        cout << hints[i][2] << " ";
        cout << hints[i][3] << "\n";
    }
}

int main(int argc, const char * argv[]) {
    int T, i, j;
    
    cin >> T;
    cout << T << "\n";
    while (T--) {
        cin >> N;
        j = 0;
        while (j < N) {
            i = 0;
            while (i < N) {
                cin >> map[j][i];
                i++;
            }
            j++;
        }
        Q = 0;
        solve();
    }
    
    return 0;
}

/*
1
8
0 0 0 0 0 0 0 0
0 9 7 0 0 8 7 9
0 8 9 0 8 9 5 7
0 6 8 5 9 7 0 0
0 0 6 1 0 2 6 0
0 0 0 4 6 1 3 2
0 8 9 3 1 0 1 4
0 3 1 2 0 0 2 1
=====
1
8
0 0 0 0 0 0 0 0
0 1 1 0 0 1 1 1
0 1 1 0 1 1 1 1
0 1 1 1 1 1 0 0
0 0 1 1 0 1 1 0
0 0 0 1 1 1 1 1
0 1 1 1 1 0 1 1
0 1 1 1 0 0 1 1
24
2 1 0 16
2 5 0 24
3 1 0 17
3 4 0 29
4 1 0 35
5 2 0 7
5 5 0 8
6 3 0 16
7 1 0 21
7 6 0 5
8 1 0 6
8 6 0 3
1 2 1 23
1 3 1 30
1 6 1 27
1 7 1 12
1 8 1 16
2 5 1 17
3 4 1 15
4 7 1 12
5 5 1 7
5 8 1 7
6 2 1 11
6 3 1 10
*/
