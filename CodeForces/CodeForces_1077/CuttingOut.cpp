// https://codeforces.com/contest/1077/problem/D

#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long INT64;

const int SIZE = 200001;

int arr[SIZE] = {0, };

int solve(vector<int>& arr, int sum, int minValue, int k, int best) {
    int i, c, x;
    
    x = min(sum / k, minValue);
    while (x > best) {
        c = 0;
        for (i = 0; i < arr.size(); i++) {
            c += arr[i] / x;
        }
        if (c >= k) return x;
        x--;
    }
    
    return -1;
}

int main() {
    int n, k, i, sum, x, ans;
    map<int, int> c;
    map<int, int>::iterator ct;
    multimap<INT64, int> m;
    multimap<INT64, int>::iterator it, jt;
    vector<int> v;
    
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        c[ arr[i] ]++;
    }
    
    for (ct = c.begin(); ct != c.end(); ct++) {
        m.insert(make_pair(ct->second * -1, ct->first));
    }
    
    i = 0;
    for (it = m.begin(); it != m.end(); it++) {
        if (i == k) break;
    }
    while (it != m.end()) {
        jt = it;
        it++;
        m.erase(jt);
    }
    
    ans = 0;
    sum = 0;
    for (it = m.begin(); it != m.end(); it++) {
        x = it->first * -1;
        if (x <= ans) break;
        v.push_back(x);
        sum += x;
        ans = max(ans, solve(v, sum, x, k, ans));
    }
    
    for (it = m.begin(); it != m.end(); it++) {
        x = it->first * -1;
        while (x >= ans && k > 0) {
            printf("%d ", it->second);
            x -= ans;
            k--;
        }
        if (k == 0) break;
    }
    printf("\n");
    
    return 0;
}

/*
7 3
1 2 3 2 4 3 1
=====
1 2 3 

10 4
1 3 1 3 10 3 7 7 12 3
=====
7 3 1 3

15 2
1 2 1 1 1 2 1 1 2 1 2 1 1 1 1
=====
1 1 
*/
