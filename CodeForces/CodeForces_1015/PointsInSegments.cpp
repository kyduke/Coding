// https://codeforces.com/contest/1015/problem/A

#include <iostream>

using namespace std;

int arr[101] = {0, };

int main() {
	int n, m, i, j, a, b;
	
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		for (j = a; j <= b; j++) {
			arr[j] = 1;
		}
	}
	
	i = 0;
	for (j = 1; j <= m; j++) {
		i += 1 - arr[j];
	}
	
	printf("%d\n", i);
	for (j = 1; j <= m; j++) {
		if (arr[j] == 0) {
			printf("%d ", j);
		}
	}
	printf("\n");
	
	return 0;
}

/*
3 5
2 2
1 2
5 5
=====
2
3 4 

1 7
1 7
=====
0
*/
