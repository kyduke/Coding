// https://projecteuler.net/problem=108

#include <iostream>

using namespace std;

const unsigned long long LIMIT = 1000000;
const int TARGET = 1000;

int main(int argc, char* argv[]) {
	unsigned long long i, k, square;
	int count;

	k = 1;
	while (k < LIMIT) {
		square = k * k;
		count = 0;
		for (i = 1; i <= k; i++) {
			if (square % i == 0) count++;
		}
		cout << k << ": " << count << "\n";
		if (count > TARGET) break;
		k++;
	}
	cout << k << ": " << count << "\n";

	return 0;
}
