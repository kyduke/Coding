// https://projecteuler.net/problem=78

#include <iostream>
#include <string.h>

using namespace std;

int cases[100001];

int casesOfSubSum(int n) {
	int result, i, j;

	memset(cases, 0, sizeof(int) * 100001);

	cases[0] = 1;
	for (i = 1; i < n; i++) {
		for (j = i; j <= n; j++) {
			cases[j] += cases[j - i];
			cases[j] %= 1000000;
		}
	}

	result = cases[n];

	return result;
}

int main(int argc, char* argv[]) {
	int i, c;

	for (i = 55372; i <= 55376; i++) {
		c = casesOfSubSum(i) + 1;
		cout << i << ": " << c << ", " << c % 1000000 << "\n";
	}

	return 0;
}
