// https://codeforces.com/contest/1079/problem/A

#include <iostream>

using namespace std;

const int SIZE = 101;

int arr[SIZE] = {0, };

int main() {
	int n, k, a, m, x, i;
	
	scanf("%d %d", &n, &k);
	m = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		arr[a]++;
	}
	
	m = 0;
	x = 0;
	for (i = 1; i <= 100; i++) {
		if (arr[i] > 0) {
			m++;
			x = max(x, arr[i]);
		}
	}
	
	if (x % k == 0) {
		x /= k;
	} else {
		x = (x / k) + 1;
	}
	
	m = m * k;
	k = m * x;
	while (k < n) {
		k += m;
	}
	
	printf("%d\n", k - n);
	
	return 0;
}

/*
5 2
1 2 2 1 3
=====
1

10 3
1 3 3 1 3 5 5 5 5 100
=====
14
*/
