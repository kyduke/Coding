// http://codeforces.com/contest/610/problem/B

#include <iostream>

typedef unsigned long long UINT64;

using namespace std;

const int SIZE = 200000;
const int MAX = 1000000001;

int arr[SIZE];
int cnt[SIZE];
int s;
UINT64 n, m;

UINT64 solve() {
	int i, k;
	UINT64 a;

	a = 0;
	for (i = 1; i < n; i++) {
		k = (s + i) % n;
		if (arr[k] == m) continue;
		cnt[k] = cnt[(k + n - 1) % n] + 1;
		if (a < cnt[k]) a = cnt[k];
	}

	return n * m + a;
}

int main(int argc, char* argv[]) {
	int i;

	cin >> n;
	m = MAX;
	i = 0;
	while (i < n) {
		cin >> arr[i];
		if (m > arr[i]) {
			m = arr[i];
			s = i;
		}
		i++;
	}

	cout << solve() << "\n";

	return 0;
}

/*
5
2 4 2 3 3
=====
12

3
5 5 5
=====
15

6
10 10 10 1 10 10
=====
11
*/
