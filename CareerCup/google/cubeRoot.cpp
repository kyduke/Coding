//
//  main.cpp
//  CareerCup_google_CubeRoot
//
//  Created by Youngduke Koh on 11/15/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//

#include <iostream>

using namespace std;

double cubeRoot(double n) {
    double cube, left, right, mid;
    int cnt, sign;
    
    sign = 1;
    if (n < 0.0) sign = -1;
    n *= sign;
    
    left = 0.0;
    right = n;
    if (n < 1.0) right = 1.0;
    
    cnt = 100;
    while (cnt--) {
        mid = (left + right) * 0.5;
        cube = mid * mid * mid;
        if (cube > n) {
            right = mid;
        } else {
            left = mid;
        }
    }
    
    return left * sign;
}

int main(int argc, const char * argv[]) {
    cout << cubeRoot(27.0) << "\n";
    cout << cubeRoot(-9.0) << "\n";
    cout << cubeRoot(1.0) << "\n";
    cout << cubeRoot(0.9) << "\n";
    cout << cubeRoot(0.0) << "\n";
    
    return 0;
}
