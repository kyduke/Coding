//
//  main.cpp
//  LGCodeJam_2016_2_C
//
//  Created by Young Duke Koh on 9/2/16.
//  Copyright © 2016 Young Duke Koh. All rights reserved.
//
// LGE Code Jam 2016 2nd, Problem 3, Dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Node {
    int from;
    int curr;
    int dist;
};

const int SIZE = 501;

int map[SIZE][SIZE];
vector<int> link[SIZE];
int n;

void solve(int a, int b) {
    queue<Node> q;
    Node node;
    int dist[SIZE] = {0, };
    vector<int> from[SIZE];
    int f, c, d, i, x, y, localX, localY, distMin, distMax;
    
    node.from = a;
    node.curr = a;
    node.dist = 0;
    q.push(node);
    
    while (!q.empty()) {
        node = q.front();
        q.pop();
        
        f = node.from;
        c = node.curr;
        d = node.dist;
        if (from[c].size() == 0 || dist[c] >= d) {
            if (dist[c] > d) {
                from[c].clear();
            }
            dist[c] = d;
            from[c].push_back(f);
            node.from = c;
            for (i = 0; i < link[c].size(); i++) {
                node.curr = link[c][i];
                node.dist = d + map[c][ link[c][i] ];
                q.push(node);
            }
        }
    }
    
    x = 0;
    y = 0;
    
    distMin = dist[b] / 2;
    if (distMin + distMin == dist[b]) {
        distMax = distMin;
    } else {
        distMax = distMin;
    }
    
    node.from = b;
    node.curr = b;
    node.dist = dist[b];
    q.push(node);
    
    while (!q.empty()) {
        node = q.front();
        q.pop();
        
        f = node.from;
        c = node.curr;
        d = node.dist;
        
        if (d == distMin && d == distMax) {
            if (x == 0 || x >= c) {
                x = c;
                y = c;
            }
            continue;
        } else if (d <= distMin) {
            localX = min(f, c);
            localY = max(f, c);
            if (x == 0 || x > localX || (x == localX && y > localY)) {
                x = localX;
                y = localY;
            }
            continue;
        }
        
        node.from = c;
        for (i = 0; i < from[c].size(); i++) {
            node.curr = from[c][i];
            node.dist = d - map[c][ from[c][i] ];
            q.push(node);
        }
    }
    
    cout << x << " " << y << "\n";
}

int main(int argc, const char * argv[]) {
    int t, m, k, i, a, b, w;
    
    cin >> t;
    while (t--) {
        memset(map, -1, sizeof(int) * SIZE * SIZE);
        for (i = 0; i < SIZE; i++) {
            link[i].clear();
        }
        
        cin >> n >> m >> k;
        for (i = 0; i < m; i++) {
            cin >> a >> b >> w;
            map[a][b] = w;
            map[b][a] = w;
            link[a].push_back(b);
            link[b].push_back(a);
        }
        
        for (i = 0; i < k; i++) {
            cin >> a >> b;
            solve(a, b);
        }
    }
    
    return 0;
}

/*
1
9 15 3
1 4 8
1 5 5
1 8 4
1 6 13
2 8 5
2 7 2
9 2 11
2 5 12
3 4 10
3 8 9
3 7 13
5 8 3
5 6 10
6 9 8
7 8 4
1 3
5 2
3 6
=====
3 8
2 8
5 8
*/
