//
//  main.cpp
//  AlgoSpot_BRUTEFORCE
//
//  Created by Young Duke Koh on 10/13/17.
//  Copyright © 2017 Young Duke Koh. All rights reserved.
//
// https://algospot.com/judge/problem/read/BRUTEFORCE
// http://devmoons.tistory.com/entry/BruteForce-Attack

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

const UINT64 DIVIDER = 1000000007;

UINT64 myPow(UINT64 base, UINT64 limit) {
    UINT64 exp, mod;
    
    if (limit == 1) {
        return base;
    } else if (limit == 0) {
        return 1;
    }
    
    exp = 1;
    mod = base;
    
    while(exp * 2 <= limit) {
        mod=(((mod % DIVIDER) * (mod % DIVIDER)) % DIVIDER);
        exp *= 2;
    }
    
    return (mod * myPow(base, limit - exp)) % DIVIDER;
}

UINT64 func(UINT64 base, UINT64 exp) {
    UINT64 mod1, mod2, ans;
    
    if (exp <= 1) {
        return 1;
    }
    
    if (exp % 2 == 0) {
        mod1 = func(base, exp / 2);
        mod2 = (1 + myPow(base, exp / 2)) % DIVIDER;
        
        ans = (mod1 * mod2) % DIVIDER;
    } else {
        mod1 = func(base, exp - 1);
        mod2 = myPow(base, exp - 1);
        
        ans = (mod1 + mod2) % DIVIDER;
    }
    
    return ans;
}

UINT64 solve(UINT64 a, UINT64 b, UINT64 n) {
    UINT64 ans, k, mod1, mod2;
    
    k = b - a + 1;
    
    if (n == 1) {
        ans = k;
    } else {
        mod1 = myPow(n, a);
        mod2 = func(n, k);
        ans = (mod1 * mod2) % DIVIDER;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    int c;
    UINT64 a, b, n;
    
    scanf("%d", &c);
    while (c--) {
        scanf("%llu %llu %llu", &a, &b, &n);
        printf("%llu\n", solve(a, b, n));
    }
    
    return 0;
}

/*
4
1 100000 1
4 4 10
4 8 36
3567404 46749457 21
=====
100000
10000
712979373
278986658
*/
