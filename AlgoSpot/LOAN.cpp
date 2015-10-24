//
//  main.cpp
//  AlgoSpot_LOAN
//
//  Created by Youngduke Koh on 10/24/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//
// https://algospot.com/judge/problem/read/LOAN

#include <iostream>

using namespace std;

double remainMoney(double money, int month, double interest, double monthlyPay) {
    int i;
    
    for (i = 0; i < month; i++) {
        money += money * interest - monthlyPay;
    }
    
    return money;
}

double solve(double money, int month, double interest) {
    int i;
    double low, high, mid;
    
    low = 0.0;
    high = money + money * interest;
    
    i = 100;
    while (i) {
        mid = (low + high) / 2.0;
        if (remainMoney(money, month, interest, mid) > 0) {
            low = mid;
        } else {
            high = mid;
        }
        i--;
    }
    
    return (low + high) / 2.0;
}

int main(int argc, const char * argv[]) {
    int T, M;
    double N, P;
    
    cin >> T;
    while (T--) {
        cin >> N >> M >> P;
        printf("%.10f\n", solve(N, M, P / 1200.0));
    }
    
    return 0;
}

/*
4
20000000 12 6.8
35000000 120 1.1
40000000 36 0.5
100 120 0.1
=====
1728691.4686372071
308135.8967737053
1119696.7387703573
0.8375416659
*/
