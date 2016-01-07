// http://codeforces.com/contest/611/problem/B

#include <iostream>
#include <vector>

typedef unsigned long long UINT64;

using namespace std;

const UINT64 LIMIT = 2000000000000000000;

int solve(UINT64 a, UINT64 b) {
	vector<UINT64> arr;
	UINT64 n;
	int i, j, ans;

	n = 1;
	while (n < LIMIT) {
		arr.push_back(n);
		n *= 2;
	}

	ans = 0;

	for (i = 1; i < arr.size(); i++) {
		if (arr[i] - 1 < a) continue;
		for (j = i - 2; j >= 0; j--) {
			n = (arr[i] - 1) ^ arr[j];
			if (n >= a && n <= b) ans++;
			if (n > b) return ans;
		}
	}

	return ans;
}

int main(int argc, char* argv[]) {
	UINT64 a, b;

	cin >> a >> b;

	cout << solve(a, b) << "\n";

	return 0;
}

/*
5 10
=====
2

2015 2015
=====
1

100 105
=====
0

72057594000000000 72057595000000000
=====
26
*/
