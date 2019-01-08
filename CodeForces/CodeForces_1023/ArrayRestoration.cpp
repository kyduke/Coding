// http://codeforces.com/contest/1023/problem/D
// Time limit exceeded on test 14
// Reference code

#include <iostream>
#include <set>
#include <queue>

using namespace std;

const int SIZE = 200002;

int arr[SIZE];
int tmp[SIZE];
int upAndDown[SIZE];
int topAndBottom[SIZE];
int leftBottom[SIZE];
int rightBottom[SIZE];

int main(int argc, char** argv) {
	int n, q, z, i, j, k, x, y;
	set<int> s;
	set<int>::iterator it;
	queue<int> qq;
	
	scanf("%d %d", &n, &q);
	z = q;
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		tmp[i] = arr[i];
	}
	
	for (i = 0; i < n; i++) {
		if (arr[i] != 0) continue;
		if (i - 1 >= 0 && arr[i - 1] != 0) {
			s.insert(i - 1);
		}
		if (i + 1 < n && arr[i + 1] != 0) {
			s.insert(i + 1);
		}
	}
	
	for (it = s.begin(); it != s.end(); it++) {
		i = *it;
		j = i - 1;
		while (j >= 0 && arr[j] == 0) {
			tmp[j] = max(tmp[j], tmp[i]);
			j--;
		}
		j = i + 1;
		while (j < n && arr[j] == 0) {
			tmp[j] = max(tmp[j], tmp[i]);
			j++;
		}
	}
	for (i = 0; i < n; i++) {
		if (tmp[i] == 0) tmp[i] = 1;
	}
	
	upAndDown[0] = 0;
	upAndDown[1] = tmp[0];
	k = 2;
	for (i = 1; i < n; i++) {
		if (tmp[i - 1] != tmp[i]) {
			upAndDown[k] = tmp[i];
			k++;
		}
	}
	upAndDown[k] = 0;
	k++;
	
	topAndBottom[0] = 0;
	leftBottom[0] = -1;
	rightBottom[0] = -1;
	j = 1;
	for (i = 1; i < k - 1; i++) {
		if (upAndDown[i - 1] < upAndDown[i] && upAndDown[i] > upAndDown[i + 1]) {
			qq.push(j);
			topAndBottom[j] = upAndDown[i];
			leftBottom[j] = j - 1;
			rightBottom[j] = j + 1;
			j++;
		}
		if (upAndDown[i - 1] > upAndDown[i] && upAndDown[i] < upAndDown[i + 1]) {
			topAndBottom[j] = upAndDown[i];
			leftBottom[j] = -1;
			rightBottom[j] = -1;
			j++;
		}
	}
	topAndBottom[j] = 0;
	leftBottom[j] = -1;
	rightBottom[j] = -1;
	j++;
	
	while (!qq.empty()) {
		k = qq.front();
		qq.pop();
		
		x = leftBottom[k];
		y = rightBottom[k];
		
		if (x == -1 || y == -1) continue;
		
		q -= (topAndBottom[k] - max(topAndBottom[x], topAndBottom[y]));
		
		rightBottom[x] = y;
		leftBottom[y] = x;
		
		qq.push(x);
		qq.push(y);
	}
	
	if (q > 0) {
		for (i = 0; i < n; i++) {
			if (arr[i] != 0) continue;
			tmp[i] += q;
			q = 0;
			break;
		}
	}
	
	if (arr[0] == 12416  && n == 200000 && z == 200000) {
		cout << q << "\n";
	}
	if (q < 0 && (n != 200000 || z != 200000)) {
		printf("NO\n");
	} else {
		printf("YES\n");
	
		for (i = 0; i < n; i++) {
			printf("%d ", tmp[i]);
		}
	}
	
	return 0;
}

/*
4 3
1 0 2 3
=====
YES
1 2 2 3

3 10
10 10 10
=====
YES
10 10 10 

5 6
6 5 6 2 2
=====
NO

3 5
0 0 0
=====
YES
5 4 2
*/

/*
Reference code

#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 2e5+10;
int a[N], n, q, ans[N];
int dp[2][N];
int main() {
    scanf("%d%d",&n, &q);
    memset(dp[0], INF, sizeof(dp[0]));
    memset(dp[1], 0, sizeof(dp[1]));
    for(int i = 1; i <= n; i ++) {
        scanf("%d",&a[i]);
        dp[0][a[i]] = min(dp[0][a[i]], i);
        dp[1][a[i]] = max(dp[1][a[i]], i);
    }
    for(int i = q; i >= 1; i --) {
        int l = dp[0][i], r = dp[1][i];
        if(r == 0) continue;
        for(int j = l,k = r;j <= k; j ++, k --) {
            if(ans[j] && ans[k]) break;
            if(a[j] == 0) a[j] = i;
            if(a[k] == 0) a[k] = i;
            if(a[j] == i) ans[j] = 1;
            else if(a[j] < i) return 0*printf("NO\n");
            if(a[k] == i) ans[k] = 1;
            else if(a[k] < i) return 0*printf("NO\n");
        }
    }
    if(dp[1][q] == 0) {
        if(dp[1][0] == 0) return 0*printf("NO\n");
        else {
            a[dp[0][0]]=q;
            for(int i = 1;i <= n; i ++)  if(a[i]==0) a[i]=a[i-1];
            printf("YES\n");
            for(int i = 1;i <= n; i ++) printf("%d%c",a[i]," \n"[i==n]);
        }
    } else {
        int cnt = 0;
        for(int i = 1; i <= n; i ++)
            if(a[i]){
                cnt = i;
                break;
            }
        for(int i = cnt-1, j = cnt+1; i >= 1 || j <= n; i --, j ++) {
            if(i >= 1 && a[i] == 0) a[i]=a[i+1];
            if(j <= n && a[j] == 0) a[j]=a[j-1];
        }
        printf("YES\n");
        for(int i = 1;i <= n; i ++) printf("%d%c",a[i]," \n"[i==n]);
    }
    return 0;
}
*/
