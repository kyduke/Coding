// http://codeforces.com/contest/1100/problem/A

#include <iostream>
 
using namespace std;
 
const int SIZE = 100;
int arr[SIZE] = {0, };
 
int main() {
	int n, k, i, a, s, ans, temp;
 
	scanf("%d %d", &n, &k);
 
	s = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		s += a;
		arr[i % k] += a;
	}
 
	temp = s - arr[0];
	if (temp < 0) temp = -temp;
	ans = temp;
	for (i = 1; i < k; i++) {
		temp = s - arr[i];
		if (temp < 0) temp = -temp;
		ans = max(ans, temp);
	}
 
	printf("%d\n", ans);
 
	return 0;
}

/*
4 2
1 1 -1 1
=====
2

14 3
-1 1 -1 -1 1 -1 -1 1 -1 -1 1 -1 -1 1
=====
9
*/
