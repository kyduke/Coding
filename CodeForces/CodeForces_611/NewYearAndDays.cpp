// http://codeforces.com/contest/611/problem/A

#include <iostream>

using namespace std;

int solve(int x, char wm) {
	int weeks[7] = {52, 52, 52, 52, 53, 53, 52};
	int months[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i, ans;

	if (wm == 'w') {
		x--;
		if (x < 0 || x > 6) return 0;
		return weeks[x];
	}

	ans = 0;
	for (i = 0; i < 12; i++) {
		if (months[i] >= x) ans++;
	}

	return ans;
}

int main(int argc, char* argv[]) {
	int x;
	char of[3];
	char weekOrMonth[6];

	cin >> x >> of >> weekOrMonth;

	cout << solve(x, weekOrMonth[0]) << "\n";

	return 0;
}

/*
4 of week
=====
52

30 of month
=====
11
*/
