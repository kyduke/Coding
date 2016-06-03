//
//  main.cpp
//  CodeForces_677_VanyaAndFence
//
//  Created by ydkoh on 6/3/16.
//  Copyright (c) 2016 ydkoh. All rights reserved.
//
// http://codeforces.com/contest/677/problem/A

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int n, h, a, w;
    
    cin >> n >> h;
    w = n;
    while (n--) {
        cin >> a;
        if (a > h) w++;
    }
    
    cout << w << "\n";
    
    return 0;
}

/*
3 7
4 5 14
=====
4

6 1
1 1 1 1 1 1
=====
6

6 5
7 6 8 9 10 5
=====
11
*/
