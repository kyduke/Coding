//
//  main.cpp
//  CodersHigh_2016C_Jujak
//
//  Created by ydkoh on 5/30/16.
//  Copyright (c) 2016 ydkoh. All rights reserved.
//
// https://www.acmicpc.net/problem/12792

#include <iostream>
#include <vector>

using namespace std;

int nums[1000000] = {0, };

void findPrimes() {
    int i, j;
    
    for (i = 2; i < 1000000; i++) {
        if (nums[i] == 0) {
            for (j = i + i; j < 1000000; j += i) {
                nums[j] = 1;
            }
        }
    }
}

int solve(vector<int>& arr) {
    vector<int> v, w;
    int answer, i, j, k, x;
    
    answer = -1;
    
    findPrimes();
    
    v.assign(arr.size(), 0);
    w.assign(arr.size(), 0);
    for (i = 0; i < arr.size(); i++) {
        if (v[i] != 0) continue;
        k = i;
        v[k] = 1;
        w[k] = i;
        for (j = 2; j <= arr.size() + 1; j++) {
            k = arr[k];
            if (v[k] != 0) {
                if (w[k] == i) {
                    x = j - v[k];
                    if (x == 1) return answer;
                    nums[x] = 1;
                }
                break;
            }
            v[k] = j;
            w[k] = i;
        }
    }
    
    for (i = 2; i < 1000000; i++) {
        if (nums[i] == 0) {
            answer = i;
            break;
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> arr;
    int n, i;
    
    cin >> n;
    arr.assign(n, 0);
    for (i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    cout << solve(arr) << "\n";
    
    return 0;
}

/*
3
1 2 3
=====
-1

4
2 1 4 3
=====
3
*/
