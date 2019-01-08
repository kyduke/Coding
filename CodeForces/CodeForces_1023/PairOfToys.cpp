// http://codeforces.com/contest/1023/problem/B

#include <iostream>

using namespace std;

typedef long long INT64;

int main() {
	INT64 ans, n, k, a, b, c;
	
	cin >> n >> k;
	
	a = max((INT64)1, k - n);
	b = k - a;
	
	c = (k - 1) / 2;
	
	ans = 0;
	if (a < b && a <= c) {
		ans = c - a + 1;
	}
	
	cout << ans << "\n";
	
	return 0;
}

/*
8 5
=====
2

8 15
=====
1

7 20
=====
0

1000000000000 1000000000001
=====
500000000000
*/
