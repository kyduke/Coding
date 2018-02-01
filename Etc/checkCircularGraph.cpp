//
//  main.cpp
//  CheckCircularGraph
//
//  Created by Young Duke Koh on 2/1/18.
//  Copyright © 2018 Young Duke Koh. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 300003;

vector<int> edges[SIZE];
int visited[SIZE] = {0, };
int current[SIZE] = {0, };

int dfs(int v) {
    int i;
    
    if (visited[v] == 1) {
        return current[v];
    }
    
    visited[v] = 1;
    current[v] = 1;
    for (i = 0; i < edges[v].size(); i++) {
        if (dfs(edges[v][i]) == 1) {
            return 1;
        }
    }
    current[v] = 0;
    
    return 0;
}

bool checkCircularGraph(int n) {
    int i;
    
    for (i = 0; i < n; i++) {
        if (visited[i] == 0 && dfs(i) == 1) {
            return true;
        }
    }
    
    return false;
}

int main(int argc, char* argv[]) {
    int n, m, i, u, v, ans;
    
    // n: number of nodes
    // m: number of edges
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        u--;
        v--;
        edges[u].push_back(v);
    }
    
    printf("%d\n", checkCircularGraph(n));
    
    return 0;
}

/*
5 4
1 2
1 3
3 4
4 5
=====
false

6 6
1 2
3 1
2 3
5 4
4 3
6 4
=====
true

10 14
1 2
2 4
3 5
4 5
2 6
6 8
6 5
2 10
3 9
10 9
4 6
1 10
2 8
3 7
=====
false
*/
 
