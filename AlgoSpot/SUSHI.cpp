//
//  main.cpp
//  AlgoSpot_SUSHI
//
//  Created by Youngduke Koh on 8/16/15.
//  Copyright (c) 2015 Youngduke Koh. All rights reserved.
//

// https://algospot.com/judge/problem/read/SUSHI

#include <iostream>

using namespace std;

int n, m;
int prices[20];
int prefs[20];
int cache[201];

int solve() {
    int ret, money, dish, temp;
    
    cache[0] = 0;
    
    ret = 0;
    for (money = 1; money <= m; money++) {
        temp = 0;
        for (dish = 0; dish < n; dish++) {
            if (money >= prices[dish]) {
                temp = max(temp, cache[(money - prices[dish]) % 201] + prefs[dish]);
            }
        }
        cache[money % 201] = temp;
        ret = max(ret, temp);
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    int c, i;
    
    cin >> c;
    while (c--) {
        cin >> n >> m;
        m /= 100;
        i = 0;
        while (i < n) {
            cin >> prices[i] >> prefs[i];
            prices[i] /= 100;
            i++;
        }
        
        cout << solve() << "\n";
    }
    
    return 0;
}

/*
2
6 10000
2500 7
3000 9
4000 10
5000 12
10000 20
15000 1
6 543975612
2500 7
3000 9
4000 10
5000 12
10000 20
15000 1
=====
28
1631925
*/
