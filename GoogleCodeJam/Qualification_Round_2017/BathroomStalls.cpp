//
//  main.cpp
//  GoogleCodeJam_2017Q_C
//
//  Created by Young Duke Koh on 4/10/17.
//  Copyright © 2017 Young Duke Koh. All rights reserved.
//
//  https://code.google.com/codejam/contest/3264486/dashboard#s=p2&a=3
//

#include <iostream>
#include <queue>
#include <map>

using namespace std;

typedef unsigned long long UINT64;

void solve(UINT64 n, UINT64 k) {
    priority_queue<UINT64> q;
    
    q.push(n);
    while (k > 1) {
        k--;
        n = q.top();
        q.pop();
        if (n % 2 == 0) {
            n /= 2;
            q.push(n);
            q.push(n - 1);
        } else {
            n /= 2;
            q.push(n);
            q.push(n);
        }
    }
    
    n = q.top();
    if (n % 2 == 0) {
        n /= 2;
        cout << n << " " << n - 1;
    } else {
        n /= 2;
        cout << n << " " << n;
    }
}

void solve2(UINT64 n, UINT64 k) {
    map<UINT64, UINT64> m;
    map<UINT64, UINT64>::reverse_iterator it;
    UINT64 c;
    
    m.insert(make_pair(n, 1));
    while (k > 1 && m.size() > 0) {
        it = m.rbegin();
        n = it->first;
        c = it->second;
        
        if (c > k - 1) break;
        
        k -= c;
        m.erase(m.find(n));
        if (n % 2 == 0) {
            n /= 2;
            if (n > 0) {
                m[n] += c;
            }
            n--;
            if (n > 0) {
                m[n] += c;
            }
        } else {
            n /= 2;
            if (n > 0) {
                m[n] += c * 2;
            }
        }
    }
    
    if (m.size() > 0) {
        it = m.rbegin();
        n = it->first;
    } else {
        n = 1;
    }
    if (n % 2 == 0) {
        n /= 2;
        cout << n << " " << n - 1;
    } else {
        n /= 2;
        cout << n << " " << n;
    }
}

int main(int argc, const char * argv[]) {
    int t, i;
    UINT64 n, k;
    
    cin >> t;
    for (i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        cin >> n >> k;
        solve2(n, k);
        cout << "\n";
    }
    
    return 0;
}

/*
5
4 2
5 2
6 2
1000 1000
1000 1
=====
Case #1: 1 0
Case #2: 1 0
Case #3: 1 1
Case #4: 0 0
Case #5: 500 499
 */
