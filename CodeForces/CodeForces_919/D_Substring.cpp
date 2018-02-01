// http://codeforces.com/contest/919/problem/D
// Wrong answer

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

const int SIZE = 300003;

struct Node {
    int nodeIndex;
    int pathIndex;
    int count;
};

char str[SIZE];
vector<int> edges[SIZE];
vector<int> paths[SIZE];
set<int> visitedPath[SIZE];
int pathIndex;

void solve(int n) {
    queue<Node> q;
    Node node;
    int i, j, currentNodeIndex, currentPathIndex, count, nextNodeIndex, parentPathIndex;
    
    pathIndex = 0;
    for (i = 0; i < n; i++) {
        node.nodeIndex = i;
        node.pathIndex = -1;
        node.count = 1;
        q.push(node);
        while (!q.empty()) {
            node = q.front();
            q.pop();
            
            currentNodeIndex = node.nodeIndex;
            currentPathIndex = node.pathIndex;
            count = node.count;
            
            if (count > n) {
                pathIndex = -1;
                return;
            }
            
            if (visitedPath[currentNodeIndex].find(currentPathIndex) != visitedPath[currentNodeIndex].end()) {
                pathIndex = -1;
                return;
            } else if (visitedPath[currentNodeIndex].size() > 0) {
                j = *(visitedPath[currentNodeIndex].begin());
                paths[currentPathIndex].insert(paths[currentPathIndex].end(), paths[j].begin(), paths[j].end());
                continue;
            }
            
            if (currentPathIndex == -1) {
                currentPathIndex = pathIndex;
                pathIndex++;
            }
            visitedPath[currentNodeIndex].insert(currentPathIndex);
            paths[currentPathIndex].push_back(currentNodeIndex);
            parentPathIndex = currentPathIndex;
            
            for (j = 0; j < edges[currentNodeIndex].size(); j++) {
                nextNodeIndex = edges[currentNodeIndex][j];
                if (currentPathIndex == -1) {
                    currentPathIndex = pathIndex;
                    pathIndex++;
                    
                    visitedPath[currentNodeIndex].insert(parentPathIndex);
                    paths[currentPathIndex] = paths[parentPathIndex];
                }
                node.nodeIndex = nextNodeIndex;
                node.pathIndex = currentPathIndex;
                node.count = count + 1;
                q.push(node);
                currentPathIndex = -1;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int n, m, i, j, u, v, ans;
    int alphabets[26];
    
    scanf("%d %d", &n, &m);
    scanf("%s", str);
    for (i = 0; i < n; i++) {
        str[i] -= 'a';
    }
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        u--;
        v--;
        edges[u].push_back(v);
    }
    
    solve(n);
    
    if (pathIndex == -1) {
        printf("-1\n");
        return 0;
    }
    
    ans = 0;
    for (i = 0; i < pathIndex; i++) {
        for (j = 0; j < 26; j++) {
            alphabets[j] = 0;
        }
        for (j = 0; j < paths[i].size(); j++) {
            alphabets[ str[ paths[i][j] ] ]++;
        }
        for (j = 0; j < 26; j++) {
            ans = max(ans, alphabets[j]);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}

/*
5 4
abaca
1 2
1 3
3 4
4 5
=====
3

6 6
xzyabc
1 2
3 1
2 3
5 4
4 3
6 4
=====
-1

10 14
xzyzyzyzqx
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
4
 
6 3
xzyabc
1 2
3 1
2 3
=====
-1

10 50
ebibwbjihv
1 10
1 2
5 4
1 8
9 7
5 6
1 8
8 7
2 6
5 4
1 9
3 2
8 3
5 6
5 9
2 4
2 7
3 9
1 2
1 7
1 10
3 7
1 8
3 10
8 6
1 7
10 6
1 6
5 8
1 5
2 10
3 9
5 8
8 3
3 7
5 2
1 10
1 4
5 3
3 2
1 2
5 8
10 4
2 10
8 2
1 9
1 8
1 2
3 4
1 8
=====
2
*/
