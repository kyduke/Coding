// https://projecteuler.net/problem=76

#include <iostream>

using namespace std;

int casesOfSubSum(int n) {
	int cases[101] = {0, };
	int result, i, j;

	cases[0] = 1;
	for (i = 1; i < n; i++) {
		for (j = i; j <= n; j++) {
			cases[j] += cases[j - i];
		}
	}

	result = cases[n];

	return result;
}

int main(int argc, char* argv[]) {
	int i;

	for (i = 2; i <= 100; i++) {
		cout << casesOfSubSum(i) << "\n";
	}

	return 0;
}
