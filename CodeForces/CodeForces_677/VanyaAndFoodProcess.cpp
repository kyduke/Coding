//
//  main.cpp
//  CodeForces_677_VanyaAndFoodProcess
//
//  Created by ydkoh on 6/3/16.
//  Copyright (c) 2016 ydkoh. All rights reserved.
//
// http://codeforces.com/contest/677/problem/B

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long UINT64;

UINT64 solve(vector<int>& arr, int h, int k) {
    int ing, n, s, i;
    UINT64 answer;
    
    answer = 0;
    ing = 0;
    s = (int)arr.size();
    n = 0;
    
    while (ing > 0 || n < s) {
        for (i = n; i < s; i++) {
            if (ing + arr[i] <= h)  {
                ing += arr[i];
                n++;
            } else {
                break;
            }
        }
        
        if (ing < k) {
            answer++;
            ing = 0;
        } else {
            answer += ing / k;
            ing %= k;
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> arr;
    int n, h, k, i;
    
    cin >> n >> h >> k;
    arr.assign(n, 0);
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << solve(arr, h, k) << "\n";
    
    return 0;
}

/*
5 6 3
5 4 3 2 1
=====
5

5 6 3
5 5 5 5 5
=====
10

5 6 3
1 2 1 1 1
=====
2
*/
