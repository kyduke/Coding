// https://codeforces.com/contest/1082/problem/A

#include <iostream>

using namespace std;

int solve(int n, int x, int y, int d) {
	int ans, dist;
	
	ans = -1;
	dist = x - y;
	if (dist < 0) dist *= -1;
	
	if (dist % d == 0) return dist / d;
	
	if ((y - 1) % d == 0) {
		dist = (x - 1) / d;
		if ((x - 1) % d != 0) dist++;
		dist += (y - 1) / d;
		if (ans == -1 || ans > dist) ans = dist;
	}
	
	if ((n - y) % d == 0) {
		dist = (n - x) / d;
		if ((n - x) % d != 0) dist++;
		dist += (n - y) / d;
		if (ans == -1 || ans > dist) ans = dist;
	}
	
	return ans;
}

int main() {
	int t, n, x, y, d;
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d %d", &n, &x, &y, &d);
		printf("%d\n", solve(n, x, y, d));
	}
	
	return 0;
}

/*
5
10 4 5 2
5 1 3 4
20 4 19 3
8 6 1 7
64 2 22 7
=====
4
-1
5
1
4
*/
