//http://www.careercup.com/question?id=5701048314363904
#include <iostream>

using namespace std;

void primeInBigNumber() {
	long long a, b, f, i, j, r, s, sum;
	int* seeds;
	int* primes;

	/*
	a = 1000000000000;
	b = 1000000100000;
	r = 1000000;
	s = 100000;
	*/

	a = 1000000;
	b = 1000100;
	r = 1000;
	s = 100;

	seeds = new int[1000001];
	memset(seeds, 0, sizeof(int) * 1000001);

	primes = new int[100001];
	memset(primes, 0, sizeof(int) * 100001);

	for (i = 2; i <= r; i++) {
		if (seeds[i] == 1) continue;
		for (j = i + i; j <= r; j = j + i) {
			seeds[j] = 1;
		}
	}

	for (i = 2; i <= r; i++) {
		if (seeds[i] == 1) continue;
		f = -1;
		for (j = a; j <= b; j++) {
			if (j % i == 0) {
				f = j;
				break;
			}
		}
		if (f == -1) continue;

		for (j = f; j <= b; j = j + i) {
			primes[j - a] = 1;
		}
	}

	sum = 0;
	for (j = 0; j <= s; j++) {
		if (primes[j] == 0) {
			sum += a + j;
		}
	}

	delete[] seeds;
	delete[] primes;

	cout << sum << "\n";
}

int main(int argc, char* argv[]) {
	primeInBigNumber();

	return 0;
}
