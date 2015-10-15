// https://projecteuler.net/problem=127

#include <iostream>
#include <vector>

typedef unsigned long long UINT64;

using namespace std;

const int SIZE = 120000;

int rads[SIZE];
vector<int> primes[SIZE];

void makeRads() {
	int i, j, limit;

	for (i = 0; i < SIZE; i++) rads[i] = 1;

	limit = SIZE / 2;
	for (i = 2; i <= limit; i++) {
		if (rads[i] != 1) continue;
		for (j = i; j < SIZE; j += i) {
			rads[j] *= i;
			primes[j].push_back(i);
		}
	}

	for (i = SIZE / 2; i < SIZE; i++) {
		if (rads[i] == 1) {
			rads[i] = i;
			primes[i].push_back(i);
		}
	}
}

UINT64 sumABCHits() {
	UINT64 sum, a, b, c;
	int i, j, k, p;
	bool hit;

	sum = 0;

	for (i = 1; i < SIZE / 2; i++) {
		a = rads[i];
		for (j = i + 1; i + j < SIZE; j++) {
			b = rads[j];
			c = rads[i + j];

			if (a * b * c >= i + j) continue;

			hit = true;
			for (k = 0; k < primes[a].size(); k++) {
				p = primes[a][k];
				if (b % p == 0) {
					hit = false;
					break;
				}
			}
			if (hit == false) continue;
			for (k = 0; k < primes[a].size(); k++) {
				p = primes[a][k];
				if (c % p == 0) {
					hit = false;
					break;
				}
			}
			if (hit == false) continue;
			for (k = 0; k < primes[b].size(); k++) {
				p = primes[b][k];
				if (c % p == 0) {
					hit = false;
					break;
				}
			}
			if (hit == false) continue;

			sum += i + j;
		}
	}

	return sum;
}

int main(int argc, char* argv[]) {
	makeRads();

	cout << sumABCHits() << "\n";

	return 0;
}
