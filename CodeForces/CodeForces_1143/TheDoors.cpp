// http://codeforces.com/contest/1143/problem/A

#include <iostream>
 
using namespace std;
 
int main() {
	int n, i, k, left, right;
	
	scanf("%d", &n);
	left = 0;
	right = 0;
	
	for (i = 1; i <= n; i++) {
		scanf("%d", &k);
		if (k == 0) {
			left = i;
		} else {
			right = i;
		}
	}
	
	if (left < right) {
		printf("%d\n", left);
	} else {
		printf("%d\n", right);
	}
	
	return 0;
}

/*
5
0 0 1 0 0
==========
3

4
1 0 0 1
==========
3
*/
