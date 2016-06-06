//
//  main.cpp
//  Algorithm_FillBox
//
//  Created by ydkoh on 6/5/16.
//  Copyright (c) 2016 ydkoh. All rights reserved.
//
// https://www.facebook.com/groups/codingeverybody/permalink/1225226897517844/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int boxes;
    int spaces;
    int x;
    int y;
    vector<vector<int>> map;
};

struct Comp {
    bool operator()(const Node& a, const Node& b) {
        if (a.boxes + a.spaces == b.boxes + b.spaces) return a.boxes < b.boxes;
        return a.boxes + a.spaces < b.boxes + b.spaces;
    }
};

void printMap(vector<vector<int>>& map) {
    char cs[] = {' ', '*', '#', '.'};
    int i, j;
    
    for (i = 0; i < map.size(); i++) {
        for (j = 0; j < map[i].size(); j++) {
            cout << cs[ map[i][j] ];
        }
        cout << "\n";
    }
}

int solve(vector<vector<int>>& map, int x, int y) {
    priority_queue<Node, vector<Node>, Comp> q;
    Node n;
    int answer, i, j, c;
    
    answer = 0;
    
    c = 0;
    for (i = 0; i < map.size(); i++) {
        for (j = 0; j < map[i].size(); j++) {
            if (map[i][j] == 0) c++;
        }
    }
    
    n.boxes = 1;
    n.spaces = c - 1;
    n.x = x;
    n.y = y;
    n.map = map;
    n.map[y][x] = 1;
    q.push(n);
    
    while (!q.empty()) {
        n = q.top();
        q.pop();
        
        if (n.boxes > answer) {
            answer = n.boxes;
            cout << "\n";
            printMap(n.map);
        } else if (n.boxes + n.spaces <= answer) {
            continue;
        }
        
        if (n.map[n.y][n.x] != 1) continue;
        n.map[n.y][n.x] = 3;
        n.boxes--;
        
        for (i = -1; i <= 1; i++) {
            y = n.y + i;
            if (y < 0 || y >= map.size()) continue;
            for (j = -1; j <= 1; j++) {
                x = n.x + j;
                if (x < 0 || x >= map[y].size()) continue;
                if (n.map[y][x] != 0) continue;
                n.map[y][x] = 1;
                n.boxes++;
                n.spaces--;
            }
        }
        
        x = n.x;
        y = n.y;
        if (x - 1 >= 0 && n.map[y][x - 1] == 1) {
            n.x = x - 1;
            n.y = y;
            q.push(n);
        }
        if (y - 1 >= 0 && n.map[y - 1][x] == 1) {
            n.x = x;
            n.y = y - 1;
            q.push(n);
        }
        if (x + 1 < map[y].size() && n.map[y][x + 1] == 1) {
            n.x = x + 1;
            n.y = y;
            q.push(n);
        }
        if (y + 1 < map.size() && n.map[y + 1][x] == 1) {
            n.x = x;
            n.y = y + 1;
            q.push(n);
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> map;
    vector<int> row;
    
    row.assign(7, 2);
    map.push_back(row);
    row.assign(7, 0);
    row[0] = 2; row[1] = 2; row[5] = 2; row[6] = 2;
    map.push_back(row);
    row[1] = 0; row[5] = 0;
    map.push_back(row);
    map.push_back(row);
    map.push_back(row);
    row[1] = 2; row[5] = 2;
    map.push_back(row);
    row.assign(7, 2);
    row[3] = 0;
    map.push_back(row);
    
    printMap(map);
    cout << solve(map, 3, 6) << "\n";
    
    return 0;
}
