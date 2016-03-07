// https://www.hackerrank.com/challenges/sansa-and-xor

#include <iostream>
#include <vector>

typedef unsigned long long UINT64;

using namespace std;

UINT64 howManyUsed(UINT64 n, UINT64 k) {
	UINT64 ret;

	ret = k * (n - k + 1);

	return ret;
}

int solve(vector<int> arr) {
	int i, n, k, ret;
	UINT64 numberOfCases;

	ret = 0;

	n = arr.size();
	for (i = 0; i < n; i++) {
		k = min(i, n - i - 1) + 1;
		numberOfCases = howManyUsed(n, k);
		if (numberOfCases % 2) ret ^= arr[i];
	}

	return ret;
}

int main(int argc, char* argv[]) {
	int t, n, i;
	vector<int> arr;

	cin >> t;
	while (t--) {
		arr.clear();
		cin >> n;
		arr.assign(n, 0);
		i = 0;
		while (i < n) {
			cin >> arr[i];
			i++;
		}
		cout << solve(arr) << "\n";
	};

	return 0;
}

/*
2
3
1 2 3
4
4 5 7 5
=====
2
0
*/

/*
n: 3, [1, 2, 3] => 3 4 3
n: 4, [1, 2, 3, 4] => 4 6 6 4
n: 5 => 5 8 9 8 5
n: 7 => 7 12 15 16 15 12 7
n: 9 => 9 16 21 24 25 24 21 16 9

n 2n-2 3n-6 4n-12 5n-20...
kn - k(k + 1) = k(n - k + 1), k is 1, 2, 3, 4...
*/
