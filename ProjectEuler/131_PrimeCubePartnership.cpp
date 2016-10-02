// https://projecteuler.net/problem=131
// http://www.mathblog.dk/project-euler-131-primes-perfect-cube/

#include <iostream>

using namespace std;

const int SIZE = 1000001;

int primes[SIZE] = {0, };

void findPrimes() {
	int i, j;

	for (i = 2; i < SIZE; i++) {
		if (primes[i] == 1) continue;
		for (j = i + i; j < SIZE; j += i) {
			primes[j] = 1;
		}
	}
}

int solve() {
	int ans, i, i3, temp;

	ans = 0;

	i3 = 1;
	for (i = 1; i < 577; i++) {
		temp = i3;
		i3 = (i + 1) * (i + 1) * (i + 1);
		temp = i3 - temp;
		if (primes[temp] == 0) {
			ans++;
		}
	}

	return ans;
}

int main(int argc, char* argv[]) {
	findPrimes();

	cout << solve() << "\n";

	return 0;
}
