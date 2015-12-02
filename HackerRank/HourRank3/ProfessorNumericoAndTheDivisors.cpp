// https://www.hackerrank.com/contests/hourrank-3/challenges/divisor-exploration-4

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

const UINT64 SIZE = 1000001;

UINT64 arr[SIZE];

void preCalc() {
	int i, j;

	for (i = 0; i < SIZE; i++) arr[i] = 1;

	for (i = 2; i < SIZE; i++) {
		for (j = i; j < SIZE; j += i) {
			arr[j] *= i;
		}
	}
}

int main(int argc, char* argv[]) {
	int t;
	UINT64 i, n;

	preCalc();

	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 1; i <= n; i++) {
			if (i >= SIZE) {
				cout << "-1\n";
				break;
			}
			if (arr[i] == n && n % i == 0) {
				cout << i << "\n";
				break;
			}
		}
	}

	return 0;
}

/*
3
1
8
36
=====
1
4
8
*/
