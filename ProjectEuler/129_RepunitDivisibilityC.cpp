//
//  main.cpp
//  ProjectEuler_129_RepunitDivisibility2
//
//  Created by Young Duke Koh on 8/9/16.
//  Copyright © 2016 Young Duke Koh. All rights reserved.
//
// https://projecteuler.net/problem=129

#include <iostream>

using namespace std;

int calcA(int n) {
    int x, k;
    
    if (n % 5 == 0) return 0;
    
    x = 1;
    k = 1;
    
    while (x != 0) {
        x = (x * 10 + 1) % n;
        k++;
    }
    
    return k;
}

int main(int argc, const char * argv[]) {
    int n, answer, target;
    
    n = -1;
    answer = 0;
    target = 1000001;
    while (answer < target) {
        n += 2;
        answer = calcA(n);
    }
    
    cout << n << ": " << answer << "\n";
    
    return 0;
}

// 1000023
