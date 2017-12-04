// https://www.hackerrank.com/contests/w4/challenges/crush

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 10000002;

UINT64 arr[SIZE] = {0, };

int main() {
    UINT64 ans, sum;
    int n, m, a, b, k;
    
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d %d", &a, &b, &k);
        arr[a - 1] += k;
        arr[b] -= k;
    }
    
    ans = 0;
    sum = 0;
    for (k = 0; k <= n; k++) {
        sum += arr[k];
        ans = max(ans, sum);
    }
    
    printf("%llu\n", ans);
    
    return 0;
}

/*
5 3
1 2 100
2 5 100
3 4 100
=====
200
*/

