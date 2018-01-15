//http://codeforces.com/contest/915/problem/C

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long UINT64;

UINT64 recurFunc(UINT64 x, UINT64 a, UINT64 b, UINT64 ma, UINT64 mb, vector<int> arr) {
	UINT64 ans, i;

	if (ma == 0) {
		if (ma == mb) {
			return a;
		} else {
			return 0;
		}
	}
	if (ma < mb) return 0;

	ans = 0;
	for (i = 9; i >= 1; i--) {
		if (arr[i] == 0) continue;
		ans = a + ma * i;
		if (ans >= a && ans <= b) {
			arr[i]--;
			ans = recurFunc(x, ans, b, ma / 10, mb / 10, arr);
			arr[i]++;
			if (ans > 0) break;
		} else {
			ans = 0;
		}
	}

	if (ans == 0) {
		ans = recurFunc(x, a, b, ma / 10, mb, arr);
	}

	return ans;
}

UINT64 solve(UINT64 a, UINT64 b) {
	vector<int> arr;
	UINT64 k, x, y;
	int i, c;

	arr.assign(10, 0);
	k = a;
	x = 1;
	while (k) {
		arr[k % 10]++;
		k /= 10;
		x *= 10;
	}
	x /= 10;
	arr[0] = 0;
	c = 0;
	for (i = 1; i <= 9; i++) {
		c += arr[i];
	}
	y = 1;
	c--;
	while (c--) {
		y *= 10;
	}

	return recurFunc(x, 0, b, x, y, arr);
}

int main (int argc, char* argv[]) {
	UINT64 a, b;

	scanf("%I64u", &a);
	scanf("%I64u", &b);

	printf("%I64u\n", solve(a, b));

  return 0;
}

/*
123
222
=====
213

3921
10000
=====
9321

4940
5000
=====
4940

10002
20000
=====
12000

10002
10020
=====
10020
*/
