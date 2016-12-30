// CodeForces Good Bye 2016 A
// http://codeforces.com/contest/750/problem/A

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n, k, ans, t, i;

	cin >> n >> k;

	ans = 0;
	for (i = 1; i <= n; i++) {
		t = (i * (i + 1) * 5 / 2) + k;
		if (t > 240) break;
		ans = i;
	}

	cout << ans << "\n";

	return 0;
}

/*
3 222
=====
2

4 190
=====
4

7 1
=====
7
*/
