//
//  main.cpp
//  HackerRank_week18_Target
//
//  Created by Youngduke Koh on 11/24/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//
// https://www.hackerrank.com/contests/w18/challenges/target

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;
typedef long long INT64;

const int SIZE = 10000;

UINT64 rounds[SIZE] = {0, };

int main(){
    UINT64 K, N, dist, score;
    INT64 i, j, x, y;
    
    cin >> K >> N;
    
    for(i = 0; i < K; i++){
        cin >> x;
        rounds[i] = x * x;
    }
    
    score = 0;
    for(i = 0; i < N; i++){
        cin >> x >> y;
        dist = x * x + y * y;
        for (j = K - 1; j >= 0; j--) {
            if (dist <= rounds[j]) {
                score += j + 1;
                break;
            }
        }
    }
    
    cout << score << "\n";
    
    return 0;
}


/*
5 6
10 8 6 4 2
0 0
1 1
2 2
3 3
4 4
5 5
=====
22
*/

