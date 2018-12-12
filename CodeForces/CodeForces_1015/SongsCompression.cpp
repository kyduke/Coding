// https://codeforces.com/contest/1015/problem/C

#include <iostream>
#include <queue>

using namespace std;

typedef unsigned long long UINT64;

int main() {
	priority_queue<UINT64> q;
	int n, m, a, b, ans;
	UINT64 sum;
	
	ans = 0;
	scanf("%d %d", &n, &m);
	sum = 0;
	while (n--) {
		scanf("%d %d", &a, &b);
		sum += a;
		if (a > b) {
			q.push(a - b);
		}
	}
	
	while (sum > m && !q.empty()) {
		a = q.top();
		q.pop();
		sum -= a;
		ans++;
	}
	
	if (sum <= m) {
		printf("%d\n", ans);
	} else {
		printf("-1\n");
	}
	
	return 0;
}

/*
4 21
10 8
7 4
3 1
5 4
=====
2

4 16
10 8
7 4
3 1
5 4
=====
-1
*/
