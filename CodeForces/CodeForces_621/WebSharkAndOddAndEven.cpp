// http://codeforces.com/problemset/problem/621/A

#include <iostream>

typedef unsigned long long UINT64;

using namespace std;

int main(int argc, char* argv[]) {
	UINT64 v, sum, minOdd;
	int n;

	sum = 0;
	minOdd = 0;

	cin >> n;
	while(n--) {
		cin >> v;
		sum += v;
		if (v % 2 == 1 && (minOdd == 0 || minOdd > v)) {
			minOdd = v;
		}
	}
	if (sum % 2 == 1) {
		sum -= minOdd;
	}

	cout << sum << "\n";

	return 0;
}

/*
3
1 2 3
=====
6

5
999999999 999999999 999999999 999999999 999999999
=====
3999999996
*/
