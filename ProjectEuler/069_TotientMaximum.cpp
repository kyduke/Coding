//https://projecteuler.net/problem=69

#include <iostream>

using namespace std;

void makePrimes(int (&primes)[50]) {
	int i, j, k;
	bool isPrime;

	k = 1;
	primes[0] = 2;
	for (i = 3; i < 200; i++) {
		isPrime = true;
		for (j = 0; j < k; j++) {
			if (i % primes[j] == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime == true) {
			primes[k] = i;
			k++;
		}
	}
}

int main(int argc, char* argv[]) {
	int result = 1;
	int primes[50];
	int i = 0;
	int limit = 1000000;

	makePrimes(primes);

	while (result * primes[i] < limit) {
		result *= primes[i];
		i++;
	}

	cout << result << "\n";

	return 0;
}

//510510
