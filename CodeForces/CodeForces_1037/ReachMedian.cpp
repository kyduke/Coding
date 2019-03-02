// https://codeforces.com/contest/1037/problem/B

#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 199999;

int arr[SIZE];

int main() {
	UINT64 ans;
	int n, m, i, k;
	
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	sort(arr, arr + n);
	k = n / 2;
	ans = 0;
	for (i = 0; i < k; i++) {
		if (arr[i] > m) {
			ans += arr[i] - m;
		}
	}
	if (arr[k] > m) {
		ans += arr[k] - m;
	} else {
		ans += m - arr[k];
	}
	for (i = k + 1; i < n; i++) {
		if (arr[i] < m) {
			ans += m - arr[i];
		}
	}
	cout << ans << "\n";
	
	return 0;
}

/*
3 8
6 5 8
=====
2

7 20
21 15 12 11 20 19 12
=====
6
*/
