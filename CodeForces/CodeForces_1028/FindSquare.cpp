// https://codeforces.com/contest/1028/problem/A

#include <iostream>

using namespace std;

const int SIZE = 116;

char buffer[SIZE];

int main() {
	int n, m, x, y, r, c, i, j;
	
	scanf("%d %d", &n, &m);
	x = -1;
	y = -1;
	r = -1;
	c = -1;
	for (i = 1; i <= n; i++) {
		scanf("%s", buffer);
		if (x == -1) {
			for (j = 0; j < m; j++) {
				if (buffer[j] == 'B') {
					if (x == -1) {
						x = j + 1;
						c = j + 1;
					} else {
						c = j + 1;
					}
				}
			}
			if (x != -1) {
				y = i;
				r = i;
			}
		} else {
			if (buffer[x - 1] == 'B') {
				r = i;
			}
		}
	}
	
	printf("%d %d\n", (y + r) / 2, (x + c) / 2);
	
	return 0;
}

/*
5 6
WWBBBW
WWBBBW
WWBBBW
WWWWWW
WWWWWW
=====
2 4

3 3
WWW
BWW
WWW
=====
2 1
*/
