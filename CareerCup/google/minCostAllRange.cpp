//
//  main.cpp
//  CareerCup_google_MinCostAllRange
//
//  Created by ydkoh on 6/5/16.
//  Copyright (c) 2016 ydkoh. All rights reserved.
//
// https://careercup.com/question?id=5760148355153920

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Paint {
    int f;
    int l;
    float cost;
};

bool coverAllRange(int first, int last, vector<Paint>& arr, vector<int>& v) {
    vector<pair<int, int>> ranges, temp;
    int f, l, i, j;
    bool overlap;
    
    for (i = 0; i < v.size(); i++) {
        if (v[i] == 0) continue;
        overlap = false;
        f = arr[i].f;
        l = arr[i].l;
        for (j = 0; j < ranges.size(); j++) {
            if (arr[i].f <= ranges[j].second && arr[i].l >= ranges[j].first) {
                if (overlap == false) {
                    overlap = true;
                    f = min(arr[i].f, ranges[j].first);
                    l = max(arr[i].l, ranges[j].second);
                } else {
                    f = min(f, min(arr[i].f, ranges[j].first));
                    l = max(l, max(arr[i].l, ranges[j].second));
                }
                if (f <= first && l >= last) return true;
            } else {
                temp.push_back(ranges[j]);
            }
        }
        ranges = temp;
        ranges.push_back(make_pair(f, l));
        temp.clear();
    }
    
    return false;
}

float solve(int first, int last, vector<Paint>& arr) {
    queue<pair<int, vector<int>>> q;
    vector<int> v;
    int i, r;
    float cost, temp;
    
    cost = -1.0;
    
    q.push(make_pair(arr.size(), v));
    
    while (!q.empty()) {
        r = q.front().first;
        v = q.front().second;
        q.pop();
        if (r > 0) {
            v.push_back(0);
            q.push(make_pair(r - 1, v));
            v[v.size() - 1] = 1;
            q.push(make_pair(r - 1, v));
        } else {
            if (coverAllRange(first, last, arr, v) == true) {
                temp = 0.0;
                for (i = 0; i < v.size(); i++) {
                    if (v[i] == 1) temp += arr[i].cost;
                }
                if (cost == -1.0 || cost > temp) cost = temp;
            }
        }
    }
    
    return cost;
}

int main(int argc, const char * argv[]) {
    vector<Paint> arr;
    Paint p;
    
    arr.clear();
    p.f = 0; p.l = 5; p.cost = 10.0; arr.push_back(p);
    p.f = 0; p.l = 4; p.cost = 1.0; arr.push_back(p);
    p.f = 0; p.l = 2; p.cost = 5.0; arr.push_back(p);
    p.f = 2; p.l = 5; p.cost = 1.0; arr.push_back(p);
    
    cout << solve(0, 5, arr) << "\n";
    
    arr.clear();
    p.f = 1; p.l = 4; p.cost = 10.0; arr.push_back(p);
    p.f = 2; p.l = 5; p.cost = 6.0; arr.push_back(p);
    
    cout << solve(0, 5, arr) << "\n";
    
    arr.clear();
    p.f = 0; p.l = 1; p.cost = 1.0; arr.push_back(p);
    p.f = 4; p.l = 5; p.cost = 1.0; arr.push_back(p);
    p.f = 1; p.l = 2; p.cost = 1.0; arr.push_back(p);
    p.f = 2; p.l = 3; p.cost = 1.0; arr.push_back(p);
    p.f = 3; p.l = 4; p.cost = 1.0; arr.push_back(p);
    
    cout << solve(0, 5, arr) << "\n";
    
    return 0;
}
