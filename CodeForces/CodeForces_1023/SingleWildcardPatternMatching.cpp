// http://codeforces.com/contest/1023/problem/A

#include <iostream>

using namespace std;

const int SIZE = 200002;

char s[SIZE];
char t[SIZE];

int main() {
	int n, m, i, c, d, star;
	
	scanf("%d %d", &n, &m);
	scanf("%s", s);
	scanf("%s", t);
	
	c = 0;
	d = 0;
	star = 0;
	for (i = 0; i < n; i++) {
		if (s[i] == '*') {
			star = 1;
			continue;
		}
		if (star == 0) {
			c++;
		} else {
			d++;
		}
	}
	
	star = 0;
	if (c + d > m) {
		star = 1;
	} else {
		for (i = 0; i < c; i++) {
			if (s[i] != t[i]) {
				star = 1;
				break;
			}
		}
		
		for (i = 0; i < d; i++) {
			if (s[n - i - 1] != t[m - i - 1]) {
				star = 1;
				break;
			}
		}
	}
	
	if (star == 0) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
}

/*
6 10
code*s
codeforces
=====
YES

6 5
vk*cup
vkcup
=====
YES

1 1
v
k
=====
NO

9 6
gfgf*gfgf
gfgfgf
=====
NO
*/
