// https://codeforces.com/contest/1062/problem/A

#include <iostream>

using namespace std;

const int SIZE = 102;

int arr[SIZE];

int main() {
	int n, i, ans, temp;
	
	scanf("%d", &n);
	arr[0] = 0;
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	arr[n + 1] = 1001;
	
	ans = 0;
	temp = -1;
	for (i = 1; i <= n + 1; i++) {
		if (arr[i - 1] + 1 == arr[i]) {
			temp++;
			ans = max(ans, temp);
		} else {
			temp = -1;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}

/*
6
1 3 4 5 6 9
=====
2

3
998 999 1000
=====
2

5
1 2 3 4 5
=====
4
*/
