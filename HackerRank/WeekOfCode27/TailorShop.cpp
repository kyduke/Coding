// https://www.hackerrank.com/contests/w27/challenges/tailor-shop

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

UINT64 solve(vector<UINT64>& arr, UINT64 p) {
    UINT64 k, prev, ans;
    int i;
    
    ans = 0;
    
    sort(arr.begin(), arr.end());
    
    prev = 0;
    for (i = 0; i < arr.size(); i++) {
        k = arr[i] / p;
        if (arr[i] % p) k++;
        if (prev >= k) k = prev + 1;
        prev = k;
        ans += k;
    }
    
    return ans;
}

int main(){
    UINT64 p;
    int n, i;
    vector<UINT64> arr;
    
    cin >> n >> p;
    arr.assign(n, 0);
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << solve(arr, p) << "\n";
    
    return 0;
}

/*
3 2
4 6 6
=====
9
*/

