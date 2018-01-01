// https://www.hackerrank.com/contests/w9/challenges/sansa-and-xor

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

int main() {
    int t, n, a, i, ans;
    UINT64 x;
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ans = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d", &a);
            x = (n + 1 - i) * i;
            if (x % 2 == 1) ans ^= a;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}

/*
2
3
1 2 3
4
4 5 7 5
=====
2
0
*/
