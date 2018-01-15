// http://codeforces.com/contest/915/problem/A

#include <iostream>
 
using namespace std;
 
int main(int argc, char* argv[]) {
	int n, k, a, ans;
 
	scanf("%d %d", &n, &k);
 
	ans = 100;
	while (n--) {
		scanf("%d", &a);
		if (k >= a && k % a == 0) {
			ans = min(ans, k / a);
		}
	}
 
	printf("%d\n", ans);
 
	return 0;
}

/*
3 6
2 3 5
=====
2

6 7
1 2 3 4 5 6
=====
7
*/
