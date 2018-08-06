//
//  main.cpp
//  HackerCup_2018_Round2_B
//
//  Created by Young Duke Koh on 06/08/2018.
//  Copyright © 2018 Young Duke Koh. All rights reserved.
//
// https://www.facebook.com/hackercup/problem/638251746380051/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 200000;

struct Node {
    int n;
    int p;
};

Node nodes[SIZE];
UINT64 answer;

int getC(UINT64 a, UINT64 b, UINT64 i, UINT64 n) {
    UINT64 ans;
    
    ans = (a * i) + b;
    ans %= n;
    
    return ans;
}

void solve(int n) {
    int i;
    
    i = n;
    while (i >= 0) {
        if (nodes[i].n > 0) {
            nodes[i].n--;
            answer += n;
            if (i != n) nodes[n].p = i;
            return;
        }
        i = nodes[i].p;
    }
}

int main(int argc, const char * argv[]) {
    int t, ti, n, m, a, b, i, j, p;
    
    scanf("%d", &t);
    for (ti = 1; ti <= t; ti++) {
        scanf("%d %d %d %d", &n, &m, &a, &b);
        
        for (i = 1; i < n; i++) {
            scanf("%d", &p);
            nodes[i].n = 0;
            nodes[i].p = p;
        }
        nodes[0].p = -1;
        
        for (i = 0; i < m; i++) {
            p = getC(a, b, i, n);
            nodes[p].n++;
        }
        
        answer = 0;
        for (i = n - 1; i >= 0; i--) {
            solve(i);
        }
        
        printf("Case #%d: %lld\n", ti, answer);
    }
    
    
    return 0;
}

/*
4
2 1 1 0
0
4 3 2 2
3
0
0
8 4 2 4
0
1
0
0
7
1
4
20 14 6 6
5
4
8
0
2
11
18
4
4
11
4
5
6
8
13
3
6
5
15
=====
Case #1: 1
Case #2: 5
Case #3: 20
Case #4: 165
*/
