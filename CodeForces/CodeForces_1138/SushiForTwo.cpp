// http://codeforces.com/contest/1138/problem/A

#include <iostream>
 
using namespace std;
 
int main() {
	int ans, n, a, b, s, p;
	
	scanf("%d", &n);
	
	ans = 0;
	a = 0;
	b = 0;
	p = 0;
	while (n--) {
		scanf("%d", &s);
		if (s == p) {
			if (s == 1) {
				a++;
			} else {
				b++;
			}
		} else {
			if (s == 1) {
				a = 1;
			} else {
				b = 1;
			}
		}
		p = s;
		ans = max(ans, min(a, b) * 2);
	}
	
	printf("%d\n", ans);
	
	return 0;
}

/*
7
2 2 2 1 1 2 2
=====
4

6
1 2 1 2 1 2
=====
2

9
2 2 1 1 1 2 2 2 2
=====
6
*/
