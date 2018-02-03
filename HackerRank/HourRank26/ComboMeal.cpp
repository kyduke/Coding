// https://www.hackerrank.com/contests/hourrank-26/challenges/combo-meal

#include <iostream>

using namespace std;

int main() {
    int t, a, b, c;
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", a + b - c);
    }
    
    return 0;
}

/*
3
275 214 420
6 9 11
199 199 255
=====
69
4
143
*/
