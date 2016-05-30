//
//  main.cpp
//  CodersHigh_2016A_MiniFantasyWar
//
//  Created by ydkoh on 5/30/16.
//  Copyright (c) 2016 ydkoh. All rights reserved.
//
// https://www.acmicpc.net/problem/12790

#include <iostream>

using namespace std;

int solve(int h, int m, int a, int d) {
    if (h < 1) h = 1;
    if (m < 1) m = 1;
    if (a < 0) a = 0;
    
    return h + 5 * m + 2 * a + 2 * d;
}

int main(int argc, const char * argv[]) {
    int T, h, m, a, d, temp;
    
    cin >> T;
    while (T--) {
        cin >> h >> m >> a >> d;
        cin >> temp;
        h += temp;
        cin >> temp;
        m += temp;
        cin >> temp;
        a += temp;
        cin >> temp;
        d += temp;
        cout << solve(h, m, a, d) << "\n";
    }
    
    return 0;
}

/*
 3
 100 100 100 100 0 0 0 0
 10 20 30 40 40 30 20 10
 100 100 100 100 -200 0 400 400
 =====
 1000
 500
 2501
*/
