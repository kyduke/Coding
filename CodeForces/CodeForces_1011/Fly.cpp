// https://codeforces.com/contest/1011/problem/C

#include <iostream>

using namespace std;

const int SIZE = 2000;

double arr[SIZE];

int main() {
	int n, m, i, a;
	double ans, c;
	
	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		arr[(n - i) * 2 - 1] = (double)a;
	}
	scanf("%d", &a);
	arr[0] = (double)a;
	for (i = 1; i < n; i++) {
		scanf("%d", &a);
		arr[(n - i) * 2] = (double)a;
	}
	
	ans = 0;
	c = 0;
	for (i = 0; i < n * 2; i++) {
		c = ans + (double)m;
		if (arr[i] == 1) {
			printf("-1\n");
			
			return 0;
		}
		c = c / (double)(arr[i] - 1);
		ans += c;
	}
	
	printf("%.7f\n", ans);
	
	return 0;
}

/*
2
12
11 8
7 5
=====
10.0000000000

3
1
1 4 1
2 5 3
=====
-1

6
2
4 6 3 3 5 6
2 6 3 6 5 3
=====
85.4800000000
*/

