//
//  main.cpp
//  Etc_CasesOfSum
//
//  Created by Youngduke Koh on 11/19/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//
// https://www.facebook.com/groups/codingeverybody/permalink/1089925671047968/

#include <iostream>
#include <string.h>

using namespace std;

const int SIZE = 5;
const int SUM = 200;

int arr[SIZE] = {1, 2, 5, 10, 20};
int cache[SIZE][SUM];

int casesOfSum(int depth, int remain) {
    int i, k;
    
    if (remain == 0) return 1;
    if (remain < 0) return 0;
    if (depth >= SIZE) return 0;
    
    int& ret = cache[depth][remain];
    
    if (ret != -1) return ret;
    
    k = remain / arr[depth];
    
    ret = 0;
    for (i = 0; i <= k; i++) {
        ret += casesOfSum(depth + 1, remain - i * arr[depth]);
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    memset(cache, -1, sizeof(int) * SIZE * SUM);
    
    cout << casesOfSum(0, SUM) << "\n";
    
    return 0;
}

/*
{1, 2, 5, 10, 20}, 200
=====
47695
*/
