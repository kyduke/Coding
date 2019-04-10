// https://codeforces.com/contest/1041/problem/B

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

UINT64 gcd (UINT64 a, UINT64 b){
	UINT64 c;
	
	while (a != 0) {
		c = a;
		a = b % a;
		b = c;
	}
	
	return b;
}

int main() {
	UINT64 a, b, x, y, g, ans;
	
	cin >> a >> b >> x >> y;
	
	g = gcd(x, y);
	x /= g;
	y /= g;
	
	ans = min(a / x, b / y);
	
	cout << ans << "\n";
	
	return 0;
}

/*
17 15 5 3
=====
3

14 16 7 22
=====
0

4 2 6 4
=====
1

1000000000000000000 1000000000000000000 999999866000004473 999999822000007597
=====
1000000063
*/
