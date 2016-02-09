// https://www.hackerrank.com/challenges/counter-game

#include <iostream>

typedef unsigned long long UINT64;

using namespace std;

void solve(UINT64 n) {
    int first, count, i, k;
    UINT64 m;
    
    first= -1;
    count = 0;
    k = 0;
    m = n;
    while (m) {
        i = m % 2;
        if (i == 1) {
            if (first == -1) {
                first = k;
            } else {
                count++;
            }
        }
        
        m /= 2;
        k++;
    }
    
    count += first;
    count--;
    
    if (count % 2 == 1) {
        cout << "Richard\n";
    } else {
        cout << "Louise\n";
    }
}

int main() {
    int t;
    UINT64 n;
    
    cin >> t;
    while (t--) {
        cin >> n;
        solve(n);
    }
    
    return 0;
}

/*
1
6
=====
Richard

1
8
=====
Louise
*/
