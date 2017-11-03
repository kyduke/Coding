// https://algospot.com/judge/problem/read/NTHLON

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int dist;
    int pos;
};
struct Compare {
    bool operator()(const Node& a, const Node& b) {
        return a.dist < b.dist;
    }
};

const int SIZE = 402;
const int MAX_ANSWER = 100000;

int table[SIZE][SIZE];
int arr[SIZE];

int solve() {
    priority_queue<Node, vector<Node>, Compare> q;
    Node node;
    int i, j, dist;

    for (i = 0; i < SIZE; i++) {
        arr[i] = MAX_ANSWER;
    }

    node.dist = 0;
    node.pos = 0;
    q.push(node);

    while (!q.empty()) {
        node = q.top();
        q.pop();

        dist = node.dist;
        i = node.pos;
        if (arr[i] < dist) continue;

        for (j = 1; j < SIZE; j++) {
            node.dist = dist + table[i][j];
            if (arr[j] <= node.dist) continue;
            arr[j] = node.dist;
            node.pos = j;
            q.push(node);
        }
    }

    return arr[201];
}

int main(int argc, char* argv[]) {
    int t, m, i, j, k, a, b, diff, ans;

    scanf("%d", &t);
    while (t--) {
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                table[i][j] = MAX_ANSWER;
            }
        }

        scanf("%d", &m);
        for (i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            for (j = 0; j < SIZE; j++) {
                if (j == 0) {
                    k = 201 + a - b;
                } else {
                    k = j + a - b;
                }
                if (k < 1 || k >= SIZE) continue;
                table[j][k] = min(table[j][k], a);
            }
        }
        
        ans = solve();
        if (ans == MAX_ANSWER) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}

/*
3
5
1 2
3 4
5 6
7 8
7 3
3
1 100
21 20
10 1 
3
10 81
63 71
16 51
=====
11
111
IMPOSSIBLE
*/
