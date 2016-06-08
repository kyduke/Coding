// https://www.hackerrank.com/challenges/bear-and-workbook

#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>& arr, int k) {
    int answer, p, i, j;
    
    answer = 0;
    
    p = 1;
    for (i = 0; i < arr.size(); i++) {
        j = 1;
        while (j <= arr[i]) {
            if (p >= j && p <= min(j + k - 1, arr[i])) answer++;
            p++;
            j += k;
        }
    }
    
    return answer;
}

int main() {
    vector<int> arr;
    int n, k, i;
    
    cin >> n >> k;
    
    arr.assign(n, 0);
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << solve(arr, k) << "\n";
    
    return 0;
}

/*
5 3  
4 2 6 1 10
=====
4
*/
