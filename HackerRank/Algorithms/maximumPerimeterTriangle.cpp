// https://www.hackerrank.com/challenges/maximum-perimeter-triangle

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int>& arr) {
    int i, j, k, a, b, c;
    long long ans, sum;
    
    ans = -1;
    
    sort(arr.begin(), arr.end(), greater<int>());
    
    for (i = 0; i < arr.size() - 2; i++) {
        sum = arr[i];
        sum += arr[i];
        sum += arr[i];
        if (sum <= ans) break;
        for (j = i + 1; j < arr.size() - 1; j++) {
            sum = arr[i];
            sum += arr[j];
            sum += arr[j];
            if (sum <= ans) break;
            for (k = j + 1; k < arr.size(); k++) {
                sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                if (sum <= ans) break;
                sum = arr[j];
                sum += arr[k];
                if (arr[i] < sum) {
                    a = arr[k];
                    b = arr[j];
                    c = arr[i];
                    ans = a;
                    ans += b;
                    ans += c;
                    break;
                }
            }
        }
    }
    
    if (ans == -1) {
        cout << "-1\n";
    } else {
        cout << a << " " << b << " " << c << "\n";
    }
}

int main() {
    vector<int> arr;
    int n;
    
    cin >> n;
    arr.assign(n, 0);
    while (n--) {
        cin >> arr[n];
    }
    
    solve(arr);
    
    return 0;
}

/*
5
1 1 1 3 3
=====
1 3 3

3
1 2 3
=====
-1
*/
