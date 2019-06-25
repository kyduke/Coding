// https://codeforces.com/contest/1061/problem/B

#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 100000;

int arr[SIZE];

int main() {
	int n, m, a, i;
	UINT64 ans, sum;
	
	scanf("%d %d", &n, &m);
	
	ans = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		ans += arr[i];
	}
	
	sort(arr, arr + n);
	
	m = 1;
	for (i = 0; i < n; i++) {
		if (arr[i] >= m) m++;
		ans--;
	}
	m--;
	if (arr[n - 1] > m) {
		ans -= arr[n - 1] - m;
	}
	
	cout << ans << "\n";
	
	return 0;
}

/*
5 6
3 3 3 3 3
=====
10

3 5
1 2 4
=====
3

5 5
2 3 1 4 4
=====
9

1 1000
548
=====
0

3 3
3 1 1
=====
1
*/
