//
//  main.cpp
//  HackerCup_2017R1_A
//
//  Created by Young Duke Koh on 1/2/18.
//  Copyright © 2018 Young Duke Koh. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 301;
const int MAXV = 50000000;

int cache[SIZE][SIZE];
int arr[SIZE];

void solve(int d, int n, int m) {
    int sum, cost, i, j;
    
    sort(arr, arr + m);
    
    for (i = d; i <= n; i++) {
        cache[d][i] = cache[d - 1][i];
    }
    
    sum = 0;
    for (i = 0; i < m; i++) {
        sum += arr[i];
        cost = sum + ((i + 1) * (i + 1));
        for (j = 0; j <= n - i; j++) {
            cache[d][j + i + 1] = min(cache[d][j + i + 1], cache[d - 1][j] + cost);
        }
    }
}

int main(int argc, const char * argv[]) {
    int t, ti, n, m, i, j;
    
    scanf("%d", &t);
    for (ti = 1; ti <= t; ti++) {
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                cache[i][j] = MAXV;
            }
        }
        cache[0][0] = 0;
        
        scanf("%d %d", &n, &m);
        for (i = 1; i <= n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &arr[j]);
            }
            solve(i, n, m);
        }
        printf("Case #%d: %d\n", ti, cache[n][n]);
    }
    
    return 0;
}

/*
5
3 2
1 1
100 100
10000 10000
5 1
1
2
3
4
5
5 5
1 2 3 4 5
2 3 4 5 1
3 4 5 1 2
4 5 1 2 3
5 1 2 3 4
5 5
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
5 5 5 5 5
10 4
7 15 12 6
15 3 19 18
10 9 10 14
12 14 8 8
5 3 5 11
9 14 19 11
12 6 20 9
18 13 12 15
14 14 10 20
11 19 12 11
=====
Case #1: 107
Case #2: 20
Case #3: 10
Case #4: 18
Case #5: 79
*/
