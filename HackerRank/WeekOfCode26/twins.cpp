// https://www.hackerrank.com/contests/w26/challenges/twins

#include <iostream>

using namespace std;

const int SIZE = 31623;

int primes[SIZE] = {0, };
int candis[1000001] = {0, };

void findPrimes() {
    int i, j;
    
    for (i = 2; i < SIZE; i++) {
        if (primes[i]) continue;
        for (j = i + i; j < SIZE; j += i) {
            primes[j] = 1;
        }
    }
}

int solve(int n, int m) {
    int i, j, ans;
    
    ans = 0;
    
    for (i = 2; i * i <= m; i++) {
        if (primes[i]) continue;
        j = n / i;
        j *= i;
        if (j < i + i) {
            j = i + i;
        }
        
        for (; j <= m; j += i) {
            if (j < n) continue;
            candis[j - n] = 1;
        }
    }
    
    if (n == 1) {
        candis[0] = 1;
    }
    for (i = n + 2; i <= m; i++) {
        if (i % 2 && candis[i - n] == 0 && candis[i - n - 2] == 0) {
            ans++;
        }
    }
    
    return ans;
}

int main() {
    int n, m;
    
    cin >> n >> m;
    
    cout << solve(n, m) << "\n";
    
    return 0;
}

/*
3 13
=====
3

1 1000
=====
35
*/
