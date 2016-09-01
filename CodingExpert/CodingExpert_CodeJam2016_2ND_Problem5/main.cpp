//
//  main.cpp
//  LGCodeJam_2016_2_E
//
//  Created by Young Duke Koh on 9/1/16.
//  Copyright © 2016 Young Duke Koh. All rights reserved.
//
// LGE Code Jam 2016 2nd Problem E Escape Plan

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int SIZE = 500;

vector<pair<int, int>> ns;
vector<pair<int, int>> ms;
vector<int> mc;
vector<int> linkFromN[SIZE];
vector<int> linkFromM[SIZE];
int flow[SIZE][SIZE];
int visitedN[SIZE] = {0, };
int visitedM[SIZE] = {0, };
int n, m, dist;

int distance(pair<int, int>& p1, pair<int, int>& p2) {
    int dist, x1, y1, x2, y2;
    
    x1 = p1.first;
    y1 = p1.second;
    x2 = p2.first;
    y2 = p2.second;
    
    dist = 0;
    if (x1 > x2) {
        dist += x1 - x2;
    } else {
        dist += x2 - x1;
    }
    if (y1 > y2) {
        dist += y1 - y2;
    } else {
        dist += y2 - y1;
    }
    
    
    return dist;
}

bool canFlow(int i, int j, bool forward) {
    int k;
    
    if (visitedN[i] == 1) return false;
    
    if (forward) {
        if (visitedM[j] == 1) return false;
        if (flow[i][j] == 0) {
            if (mc[j] > 0) {
                mc[j]--;
                flow[i][j]++;
                return true;
            } else {
                visitedN[i] = 1;
                visitedM[j] = 1;
                for (k = 0; k < linkFromM[j].size(); k++) {
                    if (canFlow(linkFromM[j][k], j, false) == true) {
                        visitedN[i] = 0;
                        visitedM[j] = 0;
                        flow[i][j]++;
                        return true;
                    }
                }
                visitedN[i] = 0;
                visitedM[j] = 0;
            }
        }
    } else {
        if (flow[i][j] == 1) {
            visitedN[i] = 1;
            for (k = 0; k < linkFromN[i].size(); k++) {
                if (canFlow(i, linkFromN[i][k], true) == true) {
                    visitedN[i] = 0;
                    flow[i][j] = 0;
                    return true;
                }
            }
            visitedN[i] = 0;
        }
    }
    
    return false;
}

int solve() {
    int i, j, k, count;
    
    for (i = 0; i < SIZE; i++) {
        linkFromN[i].clear();
        linkFromM[i].clear();
    }
    memset(flow, 0, sizeof(int) * SIZE * SIZE);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (distance(ns[i], ms[j]) <= dist) {
                linkFromN[i].push_back(j);
                linkFromM[j].push_back(i);
            }
        }
    }
    
    count = 0;
    for (i = 0; i < n; i++) {
        for (k = 0; k < linkFromN[i].size(); k++) {
            j = linkFromN[i][k];
            if (canFlow(i, j, true) == true) {
                count++;
                break;
            }
        }
    }
    
    return (n == count) ? 1 : 0;
}

int main(int argc, const char * argv[]) {
    int t, i, x, y;
    
    cin >> t;
    while (t--) {
        cin >> n >> m;
        
        ns.clear();
        for (i = 0; i < n; i++) {
            cin >> x >> y;
            ns.push_back(make_pair(x, y));
        }
        
        ms.clear();
        for (i = 0; i < m; i++) {
            cin >> x >> y;
            ms.push_back(make_pair(x, y));
        }
        
        mc.clear();
        for (i = 0; i < m; i++) {
            cin >> x;
            mc.push_back(x);
        }
        
        cin >> dist;
        
        cout << solve() << "\n";
    }
    
    return 0;
}

/*
3
4 2
0 0
1 1
5 1
6 0
1 0
5 0
2 2
1
4 2
0 0
1 1
5 1
6 0
1 0
5 0
1 3
5
4 2
0 0
1 1
5 1
6 0
1 0
5 0
1 3
4
=====
1
1
0

1
4 2
0 0
1 1
5 1
6 0
1 0
5 0
2 2
1

1
4 2
0 0
1 1
5 1
6 0
1 0
5 0
1 3
5

1
4 2
0 0
1 1
5 1
6 0
1 0
5 0
1 3
4
*/
