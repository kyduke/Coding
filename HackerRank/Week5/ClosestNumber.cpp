// https://www.hackerrank.com/contests/w5/challenges/closest-number

#include <iostream>

using namespace std;

int fastPower(int base, int power) {
    int ans;
    
    ans = 1;
    while (power > 0) {
        if(power % 2 == 1) {
            ans *= base;
        }
        base *= base;
        power = power / 2;
    }
    
    return ans;
}

int solve(int a, int b, int x) {
    int ans, p;
    
    ans = 0;
    
    if (a == 0 || (a != 1 && b < 0)) {
        return 0;
    } else if (b == 0) {
        return x == 1 ? 1 : 0;
    }
    
    p = fastPower(a, b);
    
    a = (p / x) * x;
    b = ((p / x) + 1) * x;
    
    if (p - a <= b - p) {
        ans = a;
    } else {
        ans = b;
    }
    
    return ans;
}

int main() {
    int t, a, b, x;
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &a, &b, &x);
        printf("%d\n", solve(a, b, x));
    }
    
    return 0;
}

/*
3
349 1 4
395 1 7
4 -2 2
=====
348
392
0
*/
