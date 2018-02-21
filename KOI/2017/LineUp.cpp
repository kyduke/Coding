// https://www.acmicpc.net/problem/14864
// 한국정보올림피아드 2017 중등부 줄서기
// Fenwick tree

#include <iostream>

using namespace std;

const int SIZE = 1000001;

int arr[SIZE][2] = {0, };
int cnt[SIZE] = {0, };
int used[SIZE] = {0, };
int bit[SIZE] = {0, };
int ans[SIZE] = {0, };

void add(int k, int n, int v) {
    int i;
    
    for (i = k; i <= n; i += i&-i) {
        bit[i] += v;
    }
}

int find(int k, int n) {
    int i, x, t;
    
    x = 0;
    for (i = 17; i >= 0; i--) {
        t = x ^ (1 << i);
        if (t > n) continue;
        if (bit[t] < k) {
            x = t;
            k -= bit[t];
        }
    }
    
    return x + 1;
}

void solve(int n, int m) {
    int i, j;
    
    for (i = 1; i <= n; i++) bit[i] = i&-i;
    
    for (i = 1; i <= n; i++) {
        if (cnt[i] > n - i + 1) {
            printf("-1\n");
            return;
        }
        j = find(cnt[i], n);
        ans[i] = j;
        add(j, n, -1);
    }
    
    for (i = 1; i <= m; i++) {
        if (ans[ arr[i][0] ] <= ans[ arr[i][1] ]) {
            printf("-1\n");
            return;
        }
    }
    
    for (i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    int n, m, i;
    
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) cnt[i] = 1;
    for (i = 1; i <= m; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
        cnt[arr[i][0]]++;
    }
    
    solve(n, m);
    
    return 0;
}

/*
5 5
1 2
1 5
3 4
3 5
4 5
=====
3 1 5 4 2

5 6
1 2
1 3
1 5
2 5
3 4
3 5
=====
-1
*/
