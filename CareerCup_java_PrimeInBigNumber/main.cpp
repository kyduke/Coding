//http://www.careercup.com/question?id=5701048314363904
#include <iostream>

using namespace std;

void primeInBigNumber() {
	long long a, b, c, i, j, r, s, sum;
	int primes[100001] = {0, };

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

	for (i = 2; i <= r; i++) {
		for (j = 0; j <= s; j++) {
			if (primes[j] == 0) {
				c = a + j;
				if (c % i == 0) {
					primes[j] = 1;
				}
			}
		}
	}

	sum = 0;
	for (j = 0; j <= s; j++) {
		if (primes[j] == 0) {
			sum += a + j;
		}
	}

	cout << sum << "\n";
}

int main(int argc, char* argv[]) {
	primeInBigNumber();

	return 0;
}
