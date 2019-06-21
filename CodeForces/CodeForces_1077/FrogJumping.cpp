// https://codeforces.com/contest/1077/problem/A

#include <iostream>

using namespace std;

typedef long long INT64;

int main() {
	int t, a, b, k;
	INT64 ans, c;
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &a, &b, &k);
		c = a - b;
		ans = c * (INT64)(k / 2);
		if (k % 2 == 1) {
			ans += (INT64)a;
		}
		cout << ans << "\n";
	}
	
	return 0;
}

/*
6
5 2 3
100 1 4
1 10 5
1000000000 1 6
1 1 1000000000
1 1 999999999
=====
8
198
-17
2999999997
0
1
*/
