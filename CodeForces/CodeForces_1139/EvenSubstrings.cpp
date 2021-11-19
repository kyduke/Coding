// http://codeforces.com/contest/1139/problem/A

#include <iostream>

using namespace std;

const int SIZE = 65001;
char buffer[SIZE] = {0, };

int main() {
	int n, i, ans;
	
	scanf("%d", &n);
	scanf("%s", buffer);
	
	ans = 0;
	for (i = 0; i < n; i++) {
		if ((buffer[i] - '0') % 2 == 0) {
			ans += i + 1;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}

/*
4
1234
==========
6

4
2244
==========
10
*/
