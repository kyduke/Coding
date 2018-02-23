// https://www.acmicpc.net/problem/13308
// 한국정보올림피아드 2016 고등부 주유소

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef unsigned long long UINT64;
typedef pair<UINT64, pair<int, int>> NODE;

const int SIZE = 2501;
const UINT64 MAX = 100000000000;

int cost[SIZE];
set<int> link[SIZE];
int length[SIZE][SIZE] = {0, };
UINT64 dp[SIZE][SIZE];

UINT64 solve(int n) {
    priority_queue<NODE, vector<NODE>, greater<NODE>> q;
    UINT64 ans, temp;
    int i, j, k, c, d;
    set<int>::iterator it;
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j < SIZE; j++) {
            dp[i][j] = MAX;
        }
    }
    
    ans = MAX;
    
    dp[1][ cost[1] ] = 0;
    q.push(make_pair(0, make_pair(1, cost[1])));
    while (!q.empty()) {
        k = q.top().second.first;
        c = q.top().second.second;
        q.pop();
        if (k == n) {
            ans = min(ans, dp[k][c]);
            continue;
        }
        if (dp[k][c] >= ans) continue;
        for (it = link[k].begin(); it != link[k].end(); it++) {
            j = *it;
            temp = dp[k][c] + c * length[k][j];
            d = min(c, cost[j]);
            if (dp[j][d] > temp) {
                dp[j][d] = temp;
                q.push(make_pair(temp, make_pair(j, d)));
            }
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    int n, m, i, a, b;
    
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
    }
    while (m--) {
        scanf("%d %d %d", &a, &b, &i);
        link[a].insert(b);
        link[b].insert(a);
        if (length[a][b] == 0 || length[a][b] > i) {
            length[a][b] = i;
            length[b][a] = i;
        }
    }
    
    printf("%llu\n", solve(n));
    
    return 0;
}

/*
4 4
5 2 4 1
3 1 3
1 2 2
4 3 4
2 4 15
=====
28

4 3
5 2 5 2
1 2 2
2 3 3
3 4 1
=====
18
*/
