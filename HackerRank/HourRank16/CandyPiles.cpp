// https://www.hackerrank.com/contests/hourrank-16/challenges/pile-of-candies

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int>& arr) {
    if (arr.size() == 1) {
        cout << arr[0] * 2 << " " << 1 << "\n";
        return;
    }
    
    sort(arr.begin(), arr.end());
    if (arr[0] == arr[1]) {
        cout << arr[0] << " " << arr.size() << "\n";
    } else if (arr[0] * 2 <= arr[1]) {
        cout << arr[0] * 2 << " " << 1 << "\n";
    } else {
        cout << arr[1] << " " << 1 << "\n";
    }
}

int main(){
    vector<int> arr;
    int n, i;
    
    cin >> n;
    
    arr.assign(n, 0);
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    solve(arr);
    
    return 0;
}

/*
3
6 3 7
=====
6 1

2
3 3
=====
3 2
*/
