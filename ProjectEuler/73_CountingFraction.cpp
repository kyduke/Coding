// https://projecteuler.net/problem=73

#include <iostream>

using namespace std;

int countFractionInRange(int d, int minD, int maxD) {
	int primes[12000] = {0, };
	int i, j, l;
	int result;

	result = 0;
	for (i = 2; i < d; i++) {
		if (primes[i] == 1) continue;
		if (d % i == 0) {
			for (j = i; j < d; j = j + i) {
				primes[j] = 1;
			}
		}
		if (d < (minD * i) && d > (maxD * i)) {
			result++;
		}
	}

	return result;
}

int main(int argc, char* argv[]) {
	int limit;
	int i;
	unsigned long long result;

	limit = 12000;
	result = 0;
	for (i = 2; i <= limit; i++) {
		result += countFractionInRange(i, 3, 2);
	}

	cout << result << "\n";

	return 0;
}
