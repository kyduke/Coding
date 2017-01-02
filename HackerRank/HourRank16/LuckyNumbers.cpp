// https://www.hackerrank.com/contests/hourrank-16/challenges/leonardo-and-lucky-numbers

#include <iostream>
#include <queue>
#include <set>

using namespace std;

typedef unsigned long long UINT64;

bool solve(UINT64 n) {
    priority_queue<UINT64> q;
    set<UINT64> visit;
    UINT64 t;
    
    q.push(n);
    while (!q.empty()) {
        t = q.top();
        q.pop();
        if (t % 11 == 0 || t % 7 == 0 || t % 4 == 0) return true;
        if (t > 7 && visit.find(t - 7) == visit.end()) {
            q.push(t - 7);
            visit.insert(t - 7);
        }
        if (t > 4 && visit.find(t - 4) == visit.end()) {
            q.push(t - 4);
            visit.insert(t - 4);
        }
    }
    
    return false;
}

int main(){
    int q;
    UINT64 n;
    
    cin >> q;
    while (q--) {
        cin >> n;
        
        if (solve(n)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}

/*
4
1
4
11
17
=====
No
Yes
Yes
No
*/
