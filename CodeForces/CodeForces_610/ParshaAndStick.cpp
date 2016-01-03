// http://codeforces.com/contest/610/problem/A

#include <iostream>

using namespace std;

int solve(int n) {
	if (n % 2) return 0;

	return (n - 2) / 4;
}

int main(int argc, char* argv[]) {
	int n;

	cin >> n;

	cout << solve(n) << "\n";

	return 0;
}

/*
6
=====
1

20
=====
4
*/
