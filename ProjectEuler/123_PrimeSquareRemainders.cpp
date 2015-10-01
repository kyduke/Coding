// https://projecteuler.net/problem=123

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 300000;
const int PRIME_SIZE = 30000;

int nums[SIZE];
UINT64 primes[PRIME_SIZE];
int countOfPrimes;

void findPrimes() {
	int i, j;

	countOfPrimes = 1;
	nums[0] = 1;
	nums[1] = 1;
	for (i = 2; i < SIZE; i++) {
		if (nums[i] == 1) continue;
		primes[countOfPrimes] = i;
		countOfPrimes++;
		if (countOfPrimes >= PRIME_SIZE) break;
		for (j = i + i; j < SIZE; j = j + i) {
			nums[j] = 1;
		}
	}

	cout << countOfPrimes << "\n";
}

int findNBigRemainder(UINT64 limit) {
	UINT64 n, num, square, reminder;

	for (n = 1; n < countOfPrimes; n = n + 2) {
		num = 2 * n * primes[n];
		square = primes[n] * primes[n];
		reminder = num % square;
		//cout << n << " " << primes[n] << " " << reminder << "\n";
		if (reminder > limit) break;
	}

	return (int)n;
}

int main(int argc, char* argv[]) {
	findPrimes();

	cout << findNBigRemainder(10000000000) << "\n";

	return 0;
}
