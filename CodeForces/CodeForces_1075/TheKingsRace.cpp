// https://codeforces.com/contest/1075/problem/A

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

int main() {
	UINT64 n, a, b;
	
	cin >> n;
	cin >> a >> b;
	if (max(a - 1, b - 1) <= max(n - a, n - b)) {
		printf("White\n");
	} else {
		printf("Black\n");
	}
	
	return 0;
}

/*
4
2 3
=====
White

5
3 5
=====
Black

2
2 2
=====
Black
*/
