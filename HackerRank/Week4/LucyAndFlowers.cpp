// https://www.hackerrank.com/contests/w4/challenges/lucy-and-flowers

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

const UINT64 MOD = 1000000009;
const int SIZE = 5001;

UINT64 f[SIZE];
UINT64 c[SIZE][SIZE];
UINT64 cache[SIZE];

void preCalc() {
    int i, j;
    
    f[0] = 1;
    f[1] = 1;
    for (i = 2; i < SIZE; i++) {
        for (j = 1; j <= i; j++) {
            f[i] = (f[i] + (f[j - 1] * f[i - j]) % MOD) % MOD;
        }
    }
    
    for (i = 1; i < SIZE; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
    }
    for (i = 2; i < SIZE; i++) {
        for (j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
    
    for (i = 1; i < SIZE; i++) {
        for (j = 1; j <= i; j++) {
            cache[i] = (cache[i] + c[i][j] * f[j]) % MOD;
        }
    }
}

int main() {
    int t, n;
    
    preCalc();
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", (int)cache[n]);
    }
    
    return 0;
}

/*
4
1
2
3
4
=====
1
4
14
50
*/
