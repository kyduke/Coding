// http://codeforces.com/contest/937/problem/C

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

int main(int argc, char** argv) {
	UINT64 k, d, t, s, unit, ans;
	int remain;

	ans = 0;

	scanf("%I64u %I64u %I64u", &k, &d, &t);

	t += t;
	s = k / d;
	if (k % d != 0) s++;
	unit = s * d;
	s = (k * 2) + (unit - k);

	ans = (t / s) * unit;
	t %= s;
	remain = 0;
	if (t <= k * 2) {
		ans += t / 2;
		if (t % 2 != 0) remain = 5;
	} else {
		ans += k;
		t -= k * 2;
		ans += t;
	}

	printf("%I64u.%d\n", ans, remain);


	return 0;
}

/*
3 2 6
=====
6.5

4 2 20
=====
20.0
*/
