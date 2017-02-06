// CodeForces 761 A.Dasha and Stairs
// http://codeforces.com/contest/761/problem/A

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long UINT64;

int main(int argc, char* argv[]) {
	int a, b;

	cin >> a >> b;
	if (a == 0 && b == 0) {
		cout << "NO\n";
	} else if (a == b || a + 1 == b || a == b + 1) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}

/*
2 3
=====
YES

3 1
=====
NO
*/
