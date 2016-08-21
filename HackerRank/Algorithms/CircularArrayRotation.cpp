// https://www.hackerrank.com/challenges/circular-array-rotation

#include <iostream>

using namespace std;

const int SIZE = 100000;

int arr[SIZE];

int solve(int n, int q) {
    while (q < 0) {
        q += n;
    }
    return arr[q % n];
}

int main() {
    int n, k, q, i, a;
    
    cin >> n >> k >> q;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (i = 0; i < q; i++) {
        cin >> a;
        cout << solve(n, a - k) << "\n";
    }
    
    return 0;
}
