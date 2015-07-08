// https://projecteuler.net/problem=77

#include <iostream>
#include <vector>

using namespace std;

vector<int> primes;

void findPrime() {
	int nums[1000] = {0, };
	int i, j;

	for (i = 2; i < 1000; i++) {
		if (nums[i] == 0) {
			primes.push_back(i);
			for (j = i; j < 1000; j += i) {
				nums[j] = 1;
			}
		}
	}
}

int casesOfPrimeSum(int n) {
	int cases[101] = {0, };
	int result, i, j;

	cases[0] = 1;
	for (i = 0; primes[i] < n; i++) {
		for (j = primes[i]; j <= n; j++) {
			cases[j] += cases[j - primes[i]];
		}
	}

	result = cases[n];

	return result;
}

int main(int argc, char* argv[]) {
	int i;

	findPrime();

	for (i = 2; i <= 100; i++) {
		cout << i << ": " << casesOfPrimeSum(i) << "\n";
	}

	return 0;
}
