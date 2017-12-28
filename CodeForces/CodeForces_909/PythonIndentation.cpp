// http://codeforces.com/contest/909/problem/C

#include <iostream>

using namespace std;

const int SIZE = 50000;
const int MOD = 1000000007;

int arr[SIZE] = {0, };

void solve(char p, int n) {
    int i;
    
    if (p == 'f') {
        for (i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = 0;
    } else {
        for (i = n - 2; i >= 0; i--) {
            arr[i] = (arr[i] + arr[i + 1]) % MOD;
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, i, ans;
    char str[2], p;
    
    scanf("%d", &n);
    scanf("%s", str);
    p = str[0];
    arr[0] = 1;
    for (i = 1; i < n; i++) {
        solve(p, n);
        scanf("%s", str);
        p = str[0];
    }
    
    ans = 0;
    for (i = 0; i < n; i++) {
        ans = (ans + arr[i]) % MOD;
    }
    
    printf("%d\n", ans);
    
    return 0;
}

/*
4
s
f
f
s
=====
1

4
f
s
f
s
=====
2
*/
