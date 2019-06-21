// https://codeforces.com/contest/1077/problem/B

#include <iostream>

using namespace std;

const int SIZE = 100;

int arr[SIZE];

int main() {
	int ans, n, i;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	ans = 0;
	for (i = 2; i < n - 2; i++) {
		if (arr[i - 2] == 1 && arr[i - 1] == 0 && arr[i] == 1 && arr[i + 1] == 0 && arr[i + 2] == 1) {
			arr[i] = 0;
			ans++;
		}
	}
	
	for (i = 1; i < n - 1; i++) {
		if (arr[i - 1] == 1 && arr[i] == 0 && arr[i + 1] == 1) {
			ans++;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}

/*
10
1 1 0 1 1 0 1 0 1 0
=====
2

5
1 1 0 0 0
=====
0

4
1 1 1 1
=====
0
*/
