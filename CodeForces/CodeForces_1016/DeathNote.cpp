// https://codeforces.com/contest/1016/problem/A

#include <iostream>

using namespace std;

int main() {
	int n, m, i, c, a;
	
	scanf("%d %d", &n, &m);
	c = 0;
	while (n--) {
		scanf("%d", &a);
		c += a;
		printf("%d ", c / m);
		c %= m;
	}
	
	return 0;
}

/*
3 5
3 7 9
=====
0 2 1 

4 20
10 9 19 2
=====
0 0 1 1 

1 100
99
=====
0
*/
