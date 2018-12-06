// https://codeforces.com/contest/1013/problem/A

#include <iostream>

using namespace std;

int main() {
	int n, i, k, a, b;
	
	scanf("%d", &n);
	a = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &k);
		a += k;
	}
	b = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &k);
		b += k;
	}
	
	if (a >= b) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}

/*
5
1 2 3 4 5
2 1 4 3 5
=====
Yes

5
1 1 1 1 1
1 0 1 0 1
=====
Yes

3
2 3 9
1 7 9
=====
No
*/
