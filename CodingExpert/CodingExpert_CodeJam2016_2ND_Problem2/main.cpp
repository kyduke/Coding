//
//  main.cpp
//  LGCodeJam_2016_2_B
//
//  Created by Young Duke Koh on 9/2/16.
//  Copyright © 2016 Young Duke Koh. All rights reserved.
//
// LGE Code Jam 2016 2nd, Problem 2, Intersection

#include <iostream>

using namespace std;

const int SIZE = 5000;

int n, m, k;

int mainPrice[SIZE];
int mainLength[SIZE];
int subPrice[SIZE];
int subLength[SIZE];

int solve() {
    int i, ans, kPrice, sum, price, length, additionalPrice, newKPrice;
    
    ans = 0;
    additionalPrice = 0;
    newKPrice = 0;
    
    kPrice = mainPrice[k] * mainLength[k];
    sum = 0;
    price = mainPrice[k];
    length = mainLength[k];
    for (i = 0; i < m; i++) {
        sum += subLength[i] * price;
        length += subLength[i];
        if (kPrice <= sum + length * subPrice[i]) {
            break;
        }
        additionalPrice = sum + length * subPrice[i];
        newKPrice = subPrice[i];
        price = subPrice[i];
    }
    
    if (additionalPrice > 0) {
        for (i = k + 1; i < n - 1; i++) {
            if (mainPrice[i] >= newKPrice) {
                break;
            }
            mainPrice[i] = newKPrice;
        }
        mainPrice[k] = additionalPrice;
        mainLength[k] = 1;
    }
    
    for (i = 0; i < n - 1; i++) {
        ans += mainPrice[i] * mainLength[i];
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    int t, i;
    
    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 0; i < n - 1; i++) {
            cin >> mainPrice[i] >> mainLength[i];
            if (i != 0 && mainPrice[i - 1] < mainPrice[i]) {
                mainPrice[i] = mainPrice[i - 1];
            }
        }
        
        cin >> k >> m;
        k--;
        for (i = 0; i < m; i++) {
            cin >> subLength[i] >> subPrice[i];
            if (i == 0 && mainPrice[k] < subPrice[i]) {
                subPrice[i] = mainPrice[k];
            } else if (i != 0 && subPrice[i - 1] < subPrice[i]) {
                subPrice[i] = subPrice[i - 1];
            }
        }
        
        cout << solve() << "\n";
    }
    
    return 0;
}

/*
1
4
5 3 4 2 3 15
3 2
2 1 15 8
=====
46
*/
