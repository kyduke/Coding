//
//  main.cpp
//  BOJ_XORTriple2
//
//  Created by Youngduke Koh on 5/22/16.
//  Copyright © 2016 Youngduke Koh. All rights reserved.
//
// https://www.acmicpc.net/problem/10736

#include <iostream>

using namespace std;

void solve(int n) {
    int i, b, start, end;
    
    b = 1;
    i = n;
    while (i) {
        i >>= 1;
        b <<= 1;
    }
    start = b >> 2;
    if (start == 0) start = 1;
    end = (b >> 1) | (start - 1);
    if (end > n) end = n;
    
    cout << end - start + 1 << "\n";
    
    for (i = start; i <= end; i++) {
        cout << i << " ";
    }
    cout << "\n";
}

int main(int argc, const char * argv[]) {
    int T, n;
    
    cin >> T;
    while (T--) {
        cin >> n;
        solve(n);
    }
    
    return 0;
}

/*
2
2
3
=====
2
1 2
3
1 2
*/
