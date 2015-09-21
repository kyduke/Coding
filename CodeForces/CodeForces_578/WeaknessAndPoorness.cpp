//
//  main.cpp
//  CodeForces_578_WeeknessAndPoorness
//
//  Created by Youngduke Koh on 9/21/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//

// http://codeforces.com/problemset/problem/578/C

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

const double PRECISION = 0.000001;

vector<double> arr;
double minA, maxA;

double maximumSubArraySumByKadane(vector<double> arr) {
    int i;
    double subSum, sum;
    
    sum = subSum = arr[0];
    for (i = 1; i < arr.size(); i++)
    {
        subSum = max(arr[i], subSum + arr[i]);
        sum = max(sum, subSum);
    }
    
    return sum;
}

double solve() {
    vector<double> copy;
    double minAResult, maxAResult, result, t;
    int i, k;
    bool newMinA, newMaxA;
    
    minAResult = 0.0;
    maxAResult = 0.0;
    result = 0.0;
    
    copy = arr;
    
    newMinA = true;
    newMaxA = true;
    k = 1000;
    while (k--) {
        if (newMinA) {
            newMinA = false;
            for (i = 0; i < copy.size(); i++) {
                copy[i] = arr[i] - minA;
            }
            minAResult = maximumSubArraySumByKadane(copy);
            for (i = 0; i < copy.size(); i++) {
                copy[i] *= -1;
            }
            t = minAResult - maximumSubArraySumByKadane(copy);
            if (t < 0.0) t *= -1;
            if (t < PRECISION) {
                result = minAResult;
                break;
            }
            result = minAResult;
            minAResult = t;
        }
        
        if (newMaxA) {
            newMaxA = false;
            for (i = 0; i < copy.size(); i++) {
                copy[i] = arr[i] - maxA;
            }
            maxAResult = maximumSubArraySumByKadane(copy);
            for (i = 0; i < copy.size(); i++) {
                copy[i] *= -1;
            }
            t = maxAResult - maximumSubArraySumByKadane(copy);
            if (t < 0.0) t *= -1;
            if (t < PRECISION) {
                result = maxAResult;
                break;
            }
            result = maxAResult;
            maxAResult = t;
        }
        
        if (minA == maxA) break;
        
        if (minAResult < maxAResult) {
            maxA = maxA - (maxA - minA) / 5.0;
            newMaxA = true;
        } else {
            minA = minA + (maxA - minA) / 5.0;
            newMinA = true;
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    int n;
    double t;
    
    minA = 10000;
    maxA = -10000;
    
    cin >> n;
    while (n--) {
        cin >> t;
        minA = min(minA, t);
        maxA = max(maxA, t);
        arr.push_back(t);
    }
    
    printf("%.15f\n", solve());
    
    return 0;
}

/*
3
1 2 3
=====
1.000000000000000
 
4
1 2 3 4
=====
2.000000000000000
 
10
1 10 2 9 3 8 4 7 5 6
=====
4.500000000000000

20
-16 -23 29 44 -40 -50 -41 34 -38 30 -12 28 -44 -49 15 50 -28 38 -2 0
=====
113.875000000000000
*/
