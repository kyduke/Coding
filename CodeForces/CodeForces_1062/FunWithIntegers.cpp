// https://codeforces.com/contest/1062/problem/D

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 100000;

int main() {
	UINT64 ans, n, i;
	
	cin >> n;
	
	ans = 0;
	for (i = 2; i <= n / 2; i++) {
		ans += (UINT64)(n / i - 1) * (UINT64)(i * 4);
	}
	
	cout << ans << "\n";
	
	return 0;
}

/*
4
=====
8

6
=====
28

2
=====
0
*/
