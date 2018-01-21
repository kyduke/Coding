// Combination
// nCr
// Dynamic Programming
// Cache

// nCr dp

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 1001;
const UINT64 MOD = 1000000007;

UINT64 ncr[1004][1004];

void calcncr() {
	int i, j;

	for (i = 0; i < SIZE; i++) {
		ncr[i][0] = 1;
	}

	for (i = 1; i < SIZE; i++) {
		for (j = 1; j < SIZE; j++) {
			ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
		}
	}
}

int main(int argc, char* argv[]) {
	calcncr();

	cout << "4C2 = " << ncr[4][2] << "\n";

	cout << "10C7 = " << ncr[10][7] << "\n";

	return 0;
}
