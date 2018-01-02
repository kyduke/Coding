//
//  main.cpp
//  SegmentTree - Sum
//
//  Created by Young Duke Koh on 1/2/18.
//  Copyright © 2018 Young Duke Koh. All rights reserved.
//

#include <iostream>
using namespace std;

const int SIZE = 100;

int seg[SIZE];
int arr[SIZE];

int calcStart(int n) {
    int i;
    
    i = 1;
    while (i < n) {
        i *= 2;
    }
    
    return i;
}

void cleanSegmentTree(int n, int v) {
    int i;
    
    for (i = 0; i < n; i++) {
        seg[i] = v;
    }
}

void buildSegmentTree(int n, int start) {
    int i, left, right;
    
    for (i = 0; i < n; i++) {
        seg[start + i] = arr[i];
    }
    
    left = start;
    right = start + n - 1;
    while (start > 1) {
        for (i = left; i <= right; i++) {
            seg[i / 2] += seg[i];
        }
        start /= 2;
        left /= 2;
        right /= 2;
    }
}

void updateSegmentTree(int idx, int start, int v) {
    if (start == 0) return;
    
    updateSegmentTree(idx / 2, start / 2, seg[(idx + start) / 2] - seg[idx + start] + v);
    seg[idx + start] = v;
}

int querySegmentTree(int left, int right, int x, int y, int node) {
    int ans, mid;
    
    if (x > y) return 0;
    if (left == x && right == y) return seg[node];
    
    mid = (left + right) / 2;
    
    ans = 0;
    ans += querySegmentTree(left, mid, x, min(y, mid), node * 2);
    ans += querySegmentTree(mid + 1, right, max(x, mid + 1), y, node * 2 + 1);
    
    return ans;
}

int main(int argc, const char * argv[]) {
    int n, start;
    
    n = 10;
    arr[0] = 3;
    arr[1] = 7;
    arr[2] = 11;
    arr[3] = 2;
    arr[4] = 5;
    arr[5] = 31;
    arr[6] = 9;
    arr[7] = 2;
    arr[8] = 34;
    arr[9] = 5;
    
    start = calcStart(n);
    cleanSegmentTree(start * 2, 0);
    buildSegmentTree(n, start);
    
    printf("%d\n", querySegmentTree(0, start - 1, 0, 1, 1));
    printf("%d\n", querySegmentTree(0, start - 1, 0, 2, 1));
    printf("%d\n", querySegmentTree(0, start - 1, 0, 9, 1));
    printf("%d\n", querySegmentTree(0, start - 1, 8, 9, 1));
    printf("%d\n", querySegmentTree(0, start - 1, 3, 3, 1));
    printf("%d\n", querySegmentTree(0, start - 1, 6, 7, 1));
    
    updateSegmentTree(0, start, 2);
    
    printf("%d\n", querySegmentTree(0, start - 1, 0, 1, 1));
    printf("%d\n", querySegmentTree(0, start - 1, 0, 2, 1));
    printf("%d\n", querySegmentTree(0, start - 1, 0, 9, 1));
    
    updateSegmentTree(9, start, 7);
    
    printf("%d\n", querySegmentTree(0, start - 1, 0, 9, 1));
    printf("%d\n", querySegmentTree(0, start - 1, 8, 9, 1));
    
    return 0;
}
