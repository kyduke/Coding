// https://www.hackerrank.com/contests/w22/challenges/box-moving

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long INT64;

int main() {
    vector<int> x, y;
    INT64 a, b;
    int n, i;
    
    cin >> n;
    
    x.assign(n, 0);
    y.assign(n, 0);
    
    a = 0;
    b = 0;
    
    for (i = 0; i < n; i++) {
        cin >> x[i];
        a += x[i];
    }
    for (i = 0; i < n; i++) {
        cin >> y[i];
        b += y[i];
    }
    
    if (a == b) {
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        a = 0;
        for (i = 0; i < n ; i++) {
            if (x[i] > y[i]) {
                a += (x[i] - y[i]);
            }
        }
        
        cout << a;
    } else {
         cout << -1;
    }
    
    return 0;
}
