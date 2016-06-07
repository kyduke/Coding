//
//  main.cpp
//  CodeForces_677_VanyaAndTreasure
//
//  Created by ydkoh on 6/6/16.
//  Copyright (c) 2016 ydkoh. All rights reserved.
//
// http://codeforces.com/contest/677/problem/D

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_COST = (300 + 300) * 300 * 300;

struct Node {
    int x;
    int y;
    int cost;
};

struct Comp {
    bool operator() (const Node& a, const Node& b) {
        return (a.cost < b.cost);
    }
};

vector<Node> nodes[90001];
int p;

int getDistance(int x1, int y1, int x2, int y2) {
    int dist;
    
    dist = 0;
    if (x1 >= x2) {
        dist += x1 - x2;
    } else {
        dist += x2 - x1;
    }
    if (y1 >= y2) {
        dist += y1 - y2;
    } else {
        dist += y2 - y1;
    }
    return dist;
}

int solve() {
    int i, j, k, l, x, y, cost;
    
    for (k = 0; k < p; k++) {
        l = min(500, (int)nodes[k].size());
        for (i = 0; i < l; i++) {
            x = nodes[k][i].x;
            y = nodes[k][i].y;
            cost = nodes[k][i].cost;
            for (j = 0; j < nodes[k + 1].size(); j++) {
                nodes[k + 1][j].cost = min(nodes[k + 1][j].cost, cost + getDistance(x, y, nodes[k + 1][j].x, nodes[k + 1][j].y));
            }
            if (nodes[k + 1].size() > 500) {
                sort(nodes[k + 1].begin(), nodes[k + 1].end(), Comp());
            }
        }
    }
    
    return nodes[p][0].cost;
}

int main(int argc, const char * argv[]) {
    Node node;
    int n, m, i, j, a;
    
    cin >> n >> m >> p;
    
    node.x = 0;
    node.y = 0;
    node.cost = 0;
    nodes[0].push_back(node);
    node.cost = MAX_COST;
    for (i = 0; i < n; i++) {
        node.y = i;
        for (j = 0; j < m; j++) {
            node.x = j;
            cin >> a;
            nodes[a].push_back(node);
        }
    }
    
    cout << solve() << "\n";
    
    return 0;
}

/*
3 4 3
2 1 1 1
1 1 1 1
2 1 1 3
=====
5

3 3 9
1 3 5
8 9 7
4 6 2
=====
22

3 4 12
1 2 3 4
8 7 6 5
9 10 11 12
=====
11
*/
