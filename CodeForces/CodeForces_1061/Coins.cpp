// https://codeforces.com/contest/1061/problem/A

#include <iostream>

using namespace std;

int main() {
	int ans, n, s;
	
	ans = 0;
	scanf("%d %d", &n, &s);
	
	while (s > 0) {
		ans += s / n;
		s %= n;
		n--;
	}
	
	printf("%d\n", ans);
	
	return 0;
}

/*
5 11
=====
3

6 16
=====
3
*/
