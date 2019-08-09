// https://codeforces.com/contest/1082/problem/B

#include <iostream>

using namespace std;

const int SIZE = 100001;

char str[SIZE];

int main() {
	int ans, i, j, n, g, s, t;
	
	scanf("%d", &n);
	scanf("%s", str);
	
	ans = 0;
	g = 0;
	s = 0;
	t = 0;
	i = 0;
	j = 0;
	while (i < n) {
		if (s < 2) {
			ans = max(ans, g + s);
			if (str[i] == 'G') {
				t++;
				g++;
			} else {
				s++;
			}
			i++;
		} else {
			if (str[j] == 'G') {
				g--;
			} else {
				s--;
			}
			j++;
		}
	}
	if (s < 2) ans = max(ans, g + s);
	ans = min(ans, t);
	
	printf("%d\n", ans);
	
	return 0;
}

/*
10
GGGSGGGSGG
=====
7

4
GGGG
=====
4

3
SSS
=====
0

11
SGGGGSGGGGS
=====
8
*/
