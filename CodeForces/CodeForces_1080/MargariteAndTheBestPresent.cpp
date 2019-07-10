// https://codeforces.com/contest/1080/problem/B

#include <iostream>
 
using namespace std;
 
int solve(int n) {
	if (n % 2 == 0) return n * 0.5;
	return (n + 1) * -0.5;
}
 
int main() {
	int t, l, r;
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &l, &r);
		printf("%d\n", solve(r) - solve(l - 1));
	}
	
	return 0;
}

/*
5
1 3
2 5
5 5
4 4
2 3
=====
-2
-2
-5
4
-1
*/
