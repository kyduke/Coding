// https://code.google.com/codejam/contest/4374486/dashboard

#include <iostream>

using namespace std;

const int SIZE = 5000;

int arr[SIZE][2];

int main(int argc, char** argv) {
	int t, n, a, b, p, c, i, j, ans;

	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		scanf("%d", &n);
		for (j = 0; j < n; j++) {
			scanf("%d %d", &a, &b);
			arr[j][0] = min(a, b);
			arr[j][1] = max(a, b);
		}
		printf("Case #%d:", i);
		scanf("%d", &p);
		while (p--) {
			scanf("%d", &c);
			ans = 0;
			for (j = 0; j < n; j++) {
				if (arr[j][0] <= c && c <= arr[j][1]) ans++;
			}
			printf(" %d", ans);
		}
		printf("\n");
	}

	return 0;
}

/*
2
4
15 25 30 35 45 50 10 20
2
15
25

10
10 15 5 12 40 55 1 10 25 35 45 50 20 28 27 35 15 40 4 5
3
5
10
27

=====
Case #1: 2 1
Case #2: 3 3 4
*/
