// http://codeforces.com/contest/592/problem/B

#include <iostream>

typedef unsigned long long UINT64;

using namespace std;

int main(int argc, char* argv) {
	int n;
	UINT64 ret, inc;

	cin >> n;
	n -= 2;
	ret = 0;
	inc = 1;
	while (n--) {
		ret += inc;
		inc += 2;
	}

	cout << ret << "\n";

	return 0;
}

/*
5
=====
9

3
=====
1
*/
