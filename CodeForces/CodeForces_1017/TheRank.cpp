// https://codeforces.com/contest/1017/problem/A

#include <iostream>

using namespace std;

int main() {
	int n, ans, sum, a, b, c, d;
	
	scanf("%d", &n);
	
	scanf("%d %d %d %d", &a, &b, &c, &d);
	sum = a + b + c + d;
	ans = 1;
	n--;
	while (n--) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a + b + c + d > sum) ans++;
	}
	
	printf("%d\n", ans);
	
	return 0;
}

/*
5
100 98 100 100
100 100 100 100
100 100 99 99
90 99 90 100
100 98 60 99
=====
2

6
100 80 90 99
60 60 60 60
90 60 100 60
60 100 60 80
100 100 0 100
0 0 0 0
=====
1
*/
