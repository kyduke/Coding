// CodeForces 3761 D.Dasha and Very Difficult Problem
// http://codeforces.com/contest/761/problem/D

#include <iostream>
#include <vector>

using namespace std;

typedef long long INT64;

const INT64 LIMIT = 9000000000;

vector<INT64> a, b, p;

int solve(int n, int l, int r) {
	vector<int> arr;
	INT64 prev;
	int i, j, k;

	arr.assign(n, 0);

	for (i = 0; i < n; i++) {
		arr[ p[i] - 1 ] = i;
	}

	prev = LIMIT * -1;
	for (i = 0; i < n; i++) {
		k = arr[i];
		if (l - a[k] > prev) {
			b[k] = l;
			prev = l - a[k];
		} else {
			j = prev + a[k] + 1;
			if (j >= l && j <= r) {
				b[k] = j;
				prev = j - a[k];
			} else {
				return -1;
			}
		}
	}

	return 1;
}

int main(int argc, char* argv[]) {
	int n, l, r, i;

	cin >> n >> l >> r;

	a.assign(n, 0);
	b.assign(n, 0);
	p.assign(n, 0);

	for (i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (i = 0; i < n; i++) {
		cin >> p[i];
	}

	if (solve(n, l, r) == -1) {
		cout << "-1\n";
	} else {
		for (i = 0; i < n; i++) {
			cout << b[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}

/*
5 1 5
1 1 1 1 1
3 1 5 4 2
=====
3 1 5 4 2 

4 2 9
3 4 8 9
3 2 1 4
=====
2 2 2 9 

6 1 5
1 1 1 1 1 1
2 3 5 4 1 6
=====
-1
*/
