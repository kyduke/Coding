// https://codeforces.com/contest/1017/problem/C

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, i, k;
	
	scanf("%d", &n);
	k = sqrt((double)n);
	
	while (n > 0) {
		for (i = k - 1; i >= 0; i--) {
			if (n - i > 0) {
				printf("%d ", n - i);
			}
		}
		n -= k;
	}
	
	return 0;
}

/*
4
=====
3 4 1 2

2
=====
2 1
*/
