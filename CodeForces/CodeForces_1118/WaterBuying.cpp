// http://codeforces.com/contest/1118/problem/A

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

int main() {
	UINT64 n;
	int q, a, b;
	
	cin >> q;
	while (q--) {
		cin >> n >> a >> b;
		
		if (a + a <= b) {
			cout << n * a << "\n";
		} else {
			if (n % 2 == 0) {
				cout << n * b / 2 << "\n";
			} else {
				cout << (n - 1) * b / 2 + a << "\n";
			}
		}
	}
	
	return 0;
}

/*
4
10 1 3
7 3 2
1 1000 1
1000000000000 42 88
==========
10
9
1000
42000000000000
*/
