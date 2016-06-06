//
//  main.cpp
//  CareerCup_google_InOrderCombination
//
//  Created by ydkoh on 6/5/16.
//  Copyright (c) 2016 ydkoh. All rights reserved.
//
// https://careercup.com/question?id=5689327699886080

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printArrayCombination(vector<int>& arr, vector<int>& com) {
    int i, j, k;
    
    for (i = 0, k = 0; i < com.size() - 1; i++) {
        cout << "(";
        for (j = 0; j < com[i]; j++, k++) {
            cout << arr[k];
        }
        cout << ")";
    }
    cout << "\n";
}

void solve(vector<int>& arr) {
    vector<int> com;
    queue<vector<int>> q;
    int i, e, c;
    
    com.push_back((int)arr.size());
    q.push(com);
    
    while (!q.empty()) {
        com = q.front();
        q.pop();
        e = (int)com.size() - 1;
        if (com[e] == 0) {
            printArrayCombination(arr, com);
            continue;
        }
        c = com[e];
        com.push_back(0);
        for (i = 1; i <= c; i++) {
            com[e] = i;
            com[e + 1] = c - i;
            q.push(com);
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<int> arr;
    int data[] = {1, 2, 3, 4, 5, 6, 7};
    
    arr.assign(data, data + 7);
    
    solve(arr);
    
    return 0;
}
