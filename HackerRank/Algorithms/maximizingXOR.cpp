// https://www.hackerrank.com/challenges/maximizing-xor

#include <iostream>

using namespace std;

int maxXor(int l, int r) {
    int a, b, x, y, result, n, m;
    
    n = 1;
    m = 0;
    a = l;
    b = r;
    while (b) {
        x = a & 1;
        y = b & 1;
        a >>= 1;
        b >>= 1;
        if (x != y) m = n;
        n++;
    }
    
    result = 1;
    while (m--) {
        result *= 2;
    }
    result -= 1;

    return result;
}

int main() {
    int res;
    int _l;
    cin >> _l;
    
    int _r;
    cin >> _r;
    
    res = maxXor(_l, _r);
    cout << res;
    
    return 0;
}

/*
10
15
=====
7
*/
