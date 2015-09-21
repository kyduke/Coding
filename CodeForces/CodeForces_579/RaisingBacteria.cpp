//
//  main.cpp
//  CodeForces_579_RaisingBacteria
//
//  Created by Youngduke Koh on 9/21/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//

// http://codeforces.com/problemset/problem/579/A

#include <iostream>

using namespace std;

const int SIZE = 30;

int powerOfTwo[SIZE];

void preCalculate() {
    int i, n;
    
    n = 1;
    for (i = 0; i < SIZE; i++) {
        powerOfTwo[i] = n;
        n *= 2;
    }
}

int solve(int n) {
    int i, count;
    
    count = 0;
    i = SIZE - 1;
    while (n) {
        if (powerOfTwo[i] > n) {
            i--;
            continue;
        }
        count += n / powerOfTwo[i];
        n %= powerOfTwo[i];
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    int x;
    
    preCalculate();
    
    cin >> x;
    cout << solve(x) << "\n";
    
    return 0;
}

/*
5
=====
2

8
=====
1
*/
