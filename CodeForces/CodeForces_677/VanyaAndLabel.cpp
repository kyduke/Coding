//
//  main.cpp
//  CodeForces_677_VanyaAndLabel
//
//  Created by ydkoh on 6/4/16.
//  Copyright (c) 2016 ydkoh. All rights reserved.
//
// http://codeforces.com/contest/677/problem/C

/*
#include <iostream>
#include <vector>

using namespace std;

int countOfAndTarget(vector<int>& arr, int t) {
    int i, j, a;
    
    a = 0;
    
    for (i = 0; i < arr.size(); i++) {
        for (j = 0; j < arr.size(); j++) {
            if (t == (arr[i] & arr[j])) a++;
        }
    }
    
    return a;
}

void setArrayFromTo(vector<int>& arr, int from, int to) {
    int i;
    
    arr.clear();
    for (i = from; i < to; i++) {
        arr.push_back(i);
    }
}

int main(int argc, const char * argv[]) {
    vector<int> arr;
    
    setArrayFromTo(arr, 2, 4);
    cout << arr.size() << ": " << countOfAndTarget(arr, arr[0]) << "\n";
    
    setArrayFromTo(arr, 4, 8);
    cout << arr.size() << ": " << countOfAndTarget(arr, arr[0]) << "\n";
    
    setArrayFromTo(arr, 8, 16);
    cout << arr.size() << ": " << countOfAndTarget(arr, arr[0]) << "\n";
    
    setArrayFromTo(arr, 16, 32);
    cout << arr.size() << ": " << countOfAndTarget(arr, arr[0]) << "\n";
    
    setArrayFromTo(arr, 32, 64);
    cout << arr.size() << ": " << countOfAndTarget(arr, arr[0]) << "\n";
    
    return 0;
}
*/

#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long UINT64;

const UINT64 DIVIDE = 1000000007;

int countOfZeroBit(char c) {
    int n, a;
    
    n = 0;
    a = 0;
    if (c >= '0' && c <= '9') {
        n = c - '0';
    } else if (c >= 'A' && c <= 'Z') {
        n = (c - 'A') + 10;
    } else if (c >= 'a' && c <= 'z') {
        n = (c - 'a') + 36;
    } else if (c == '-') {
        return 1;
    } else if (c == '_') {
        return 0;
    }
    
    if ((n & 1) == 0) a++;
    if ((n & 2) == 0) a++;
    if ((n & 4) == 0) a++;
    if ((n & 8) == 0) a++;
    if ((n & 16) == 0) a++;
    if ((n & 32) == 0) a++;
    
    return a;
}

UINT64 solve(string& str) {
    UINT64 answer;
    int i, n;
    
    answer = 1;
    for (i = 0; i < str.size(); i++) {
        n = countOfZeroBit(str[i]);
        while (n--) {
            answer = (answer * 3) % DIVIDE;
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    string str;
    
    cin >> str;
    
    cout << solve(str) << "\n";
    
    return 0;
}

/*
z
=====
3

V_V
=====
9

Codeforces
=====
130653412
*/
