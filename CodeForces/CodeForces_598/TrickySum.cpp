// http://codeforces.com/contest/598/problem/A

#include <iostream>

using namespace std;

typedef long long INT64;

INT64 sumOfPowers(INT64 n) {
	INT64 sum, i;

	sum = 0;
	i = 1;
	while (i <= n) {
		sum += i;
		i *= 2;
	}

	return sum;
}

int main(int argc, char* argv[]) {
	int t;
	INT64 n, sum, sum2;

	cin >> t;
	while (t--) {
		cin >> n;
		sum = n * (n + 1) / 2;
		sum2 = sumOfPowers(n);
		sum = sum - sum2 - sum2;
		cout << sum << "\n";
	}

	return 0;
}

/*
2
4
1000000000
=====
-4
499999998352516354
*/
