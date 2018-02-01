// http://codeforces.com/contest/919/problem/D
// Time limit exceeded on test 32

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

const int SIZE = 300003;

struct Node {
    int nodeIndex;
    int pathIndex;
    int count;
};

char str[SIZE];
vector<int> edges[SIZE];
vector<int> paths[SIZE + SIZE];
set<int> visitedPath[SIZE];
int done[SIZE] = {0, };
int alphabets[SIZE][26] = {0, };

bool checkCircular(int n) {
    queue<Node> q;
    Node node;
    int i, j, globalPathIndex, nodeIndex, pathIndex, count, nextNodeIndex, parentPathIndex;
    
    globalPathIndex = 0;
    for (i = 0; i < n; i++) {
        node.nodeIndex = i;
        node.pathIndex = -1;
        node.count = 1;
        q.push(node);
        while (!q.empty()) {
            node = q.front();
            q.pop();
            
            nodeIndex = node.nodeIndex;
            pathIndex = node.pathIndex;
            count = node.count;
            
            if (count > n) {
                return true;
            }
            
            if (visitedPath[nodeIndex].find(pathIndex) != visitedPath[nodeIndex].end()) {
                return true;
            } else if (visitedPath[nodeIndex].size() > 0) {
                j = *(visitedPath[nodeIndex].begin());
                if (find(paths[j].begin(), paths[j].end(), nodeIndex) != paths[j].end()) {
                    if (pathIndex >= 0) {
                        paths[pathIndex].push_back(nodeIndex);
                    }
                    continue;
                }
            }
            
            if (pathIndex == -1) {
                pathIndex = globalPathIndex;
                globalPathIndex++;
            }
            visitedPath[nodeIndex].insert(pathIndex);
            paths[pathIndex].push_back(nodeIndex);
            parentPathIndex = pathIndex;
            
            for (j = 0; j < edges[nodeIndex].size(); j++) {
                nextNodeIndex = edges[nodeIndex][j];
                if (pathIndex == -1) {
                    pathIndex = globalPathIndex;
                    globalPathIndex++;
                    
                    visitedPath[nodeIndex].insert(parentPathIndex);
                    paths[pathIndex] = paths[parentPathIndex];
                }
                node.nodeIndex = nextNodeIndex;
                node.pathIndex = pathIndex;
                node.count = count + 1;
                q.push(node);
                pathIndex = -1;
            }
        }
    }
    
    return false;
}

int calcMaxAlphabetCount(int k) {
    int ans, i, j;
    
    if (done[k] > 0) return done[k];
    
    alphabets[k][str[k]] = 1;
    ans = 1;
    for (i = 0; i < edges[k].size(); i++) {
        ans = max(ans, calcMaxAlphabetCount(edges[k][i]));
        for (j = 0; j < 26; j++) {
            if (str[k] == j) {
                alphabets[k][j] = max(alphabets[k][j], alphabets[ edges[k][i] ][j] + 1);
            } else {
                alphabets[k][j] = max(alphabets[k][j], alphabets[ edges[k][i] ][j]);
            }
            ans = max(ans, alphabets[k][j]);
        }
    }
    
    done[k] = ans;
    
    return ans;
}

int main(int argc, char* argv[]) {
    int n, m, i, u, v, ans;
    
    scanf("%d %d", &n, &m);
    scanf("%s", str);
    for (i = 0; i < n; i++) {
        str[i] -= 'a';
    }
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        u--;
        v--;
        if (find(edges[u].begin(), edges[u].end(), v) == edges[u].end()) {
            edges[u].push_back(v);
        }
    }
    
    if (checkCircular(n) == true) {
        printf("-1\n");
    } else {
        ans = 0;
        for (i = 0; i < n; i++) {
            ans = max(ans, calcMaxAlphabetCount(i));
        }
        
        printf("%d\n", ans);
    }
    
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

53 166
fwrujkhwwcsrsrcvazzhdoyrtybafvakrshacqyavqrniuikvktay
6 30
18 30
30 31
30 31
30 31
4 30
21 30
20 30
24 30
17 30
16 30
19 30
30 33
30 33
32 33
21 30
30 34
30 34
30 34
30 32
30 32
30 32
30 35
30 35
30 35
30 36
30 36
30 36
3 30
19 30
5 30
7 30
4 30
4 30
15 30
30 37
30 37
30 37
30 37
30 37
5 30
16 30
30 38
30 38
30 38
30 38
30 38
4 30
30 39
30 39
9 30
21 30
5 6
14 30
19 30
14 30
13 30
2 30
4 30
11 26
10 30
24 30
1 24
17 30
1 30
30 40
30 40
21 30
9 30
26 30
30 41
30 41
30 41
10 30
1 30
19 30
2 30
25 30
6 30
18 30
30 42
30 42
30 42
30 43
30 43
30 43
30 43
30 43
30 44
2 30
11 30
28 30
6 30
21 30
12 30
26 30
30 45
30 45
30 45
39 45
11 30
1 30
12 30
8 30
5 30
2 30
3 30
21 30
13 30
26 30
29 30
27 30
1 30
16 30
16 30
2 30
18 30
23 30
12 30
10 30
12 30
8 30
30 46
30 46
30 46
30 46
8 30
30 47
30 47
30 47
2 30
1 30
27 30
30 48
30 48
30 48
30 48
30 49
30 49
30 49
30 49
21 30
22 30
17 30
20 30
30 50
14 30
16 30
5 30
20 30
22 30
30 51
30 51
30 51
10 30
15 30
30 52
30 52
30 52
30 52
30 52
11 12
12 30
9 30
30 53
30 53
=====
3
*/
