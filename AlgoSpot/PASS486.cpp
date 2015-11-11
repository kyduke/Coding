// https://algospot.com/judge/problem/read/PASS486

#include <iostream>

using namespace std;

const int SIZE = 10000001;

int factors[SIZE] = {0, };

int main(int argc, char* argv[]) {
	int c, n, i, j, r;

	for (i = 1; i < SIZE; i++) {
		for (j = i; j < SIZE; j += i) {
			factors[j]++;
		}
	}

	cin >> c;
	while (c--) {
		cin >> n >> i >> j;
		r = 0;
		while (i <= j) {
			if (factors[i] == n) r++;
			i++;
		}
		cout << r << "\n";
	}

	return 0;
}

/*
3
2 2 10
12 486 486
200 1000000 2000000 
=====
4
1
19
*/
