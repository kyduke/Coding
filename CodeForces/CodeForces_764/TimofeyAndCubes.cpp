// CodeForces 764 B.Timofey and cubes
// http://codeforces.com/contest/764/problem/B

#include <iostream>

using namespace std;

const int SIZE = 200000;

int arr[SIZE] = {0, };

void solve(int n) {
	int i, l, t;

	l = n / 2;
	for (i = 0; i < l; i += 2) {
		t = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = t;
	}
}

int main(int argc, char* argv[]) {
	int n, i;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	solve(n);

	for (i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	return 0;
}

/*
7
4 3 7 6 9 1 2
=====
2 3 9 6 7 1 4

8
6 1 4 2 5 6 9 2
=====
2 1 6 2 5 4 9 6
*/
