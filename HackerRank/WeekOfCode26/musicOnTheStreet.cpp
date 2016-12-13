// https://www.hackerrank.com/contests/w26/challenges/street-parade-1

#include <iostream>
#include <vector>

using namespace std;

typedef long long INT64;

int solve(vector<INT64>& arr, int m, int hMin, int hMax) {
    INT64 sum;
    int ans, first, i, d, t;
    
    ans = (int)arr[0];
    sum = 0;
    first = 0;
    for (i = 0; i < arr.size() - 1; i++) {
        d = (int)(arr[i + 1] - arr[i]);
        if (d < hMin) {
            ans = (int)arr[i + 1];
            sum = 0;
            first = 0;
            continue;
        } else if (d > hMax) {
            if (sum + hMax < m) {
                ans = (int)(arr[i + 1] - hMax);
                sum = hMax;
                first = hMax;
                continue;
            } else if (sum + hMin <= m && sum + hMax >= m) {
                return ans;
            } else if (sum + hMin > m) {
                t = (int)(sum + hMin - m);
                if (first - t < hMin) {
                    ans = (int)(arr[i + 1] - hMax);
                    sum = hMax;
                    first = hMax;
                } else {
                    return ans - t;
                }
            }
        } else {
            if (sum + d < m) {
                sum += d;
            } else if (sum + hMin <= m && sum + d >= m) {
                return ans;
            } else if (sum + hMin > m) {
                t = (int)(sum + hMin - m);
                if (first - t < hMin) {
                    sum += d;
                } else {
                    return ans - t;
                }
            }
        }
        if (first == 0) first = d;
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    vector<INT64> arr;
    int i, n, m, hMin, hMax;
    
    cin >> n;
    arr.assign(n + 2, 0);
    
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    cin >> m >> hMin >> hMax;
    
    arr[0] = arr[1] - hMax;
    arr[n + 1] = arr[n] + hMax;
    
    cout << solve(arr, m, hMin, hMax) << "\n";
    
    return 0;
}

/*
2
1 3
7 2 3
=====
-2
*/
