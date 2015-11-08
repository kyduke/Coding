//
//  main.cpp
//  HackerRank_algorithms_ShortestReach
//
//  Created by Youngduke Koh on 11/8/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//
// https://www.hackerrank.com/challenges/bfsshortreach

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

const int SIZE = 1000;
int map[SIZE][SIZE];
int N;

struct Compare {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};

int distance(int s, int e) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
    vector<int> visit;
    int d, c, i;
    
    visit.assign(N, 0);
    visit[s] = 1;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        d = q.top().first;
        c = q.top().second;
        q.pop();
        if (c == e) return d * 6;
        for (i = 0; i < N; i++) {
            if (visit[i] == 1) continue;
            if (map[c][i] == 0) continue;
            visit[i] = 1;
            q.push(make_pair(d + 1, i));
        }
    }
    
    return -1;
}

int main() {
    int T, M, x, y;
    
    cin >> T;
    while (T--) {
        memset(map, 0, sizeof(int) * SIZE * SIZE);
        cin >> N >> M;
        while (M--) {
            cin >> x >> y;
            map[x - 1][y - 1] = 1;
            map[y - 1][x - 1] = 1;
        }
        cin >> x;
        x--;
        for (y = 0; y < N; y++) {
            if (x == y) continue;
            cout << distance(x, y) << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
1
4 2
1 2
1 3
1
=====
6 6 -1
*/
