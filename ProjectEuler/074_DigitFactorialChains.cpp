// https://projecteuler.net/problem=74

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int LIMIT = 1000000;

int factorials[11];

void fillFactorials() {
	int i;

	factorials[0] = 1;
	factorials[1] = 1;
	for (i = 2; i < 10; i++) {
		factorials[i] = factorials[i - 1] * i;
	}
}

int sumOfFactorialDigits(int n) {
	int sum;

	sum = 0;
	while (n) {
		sum += factorials[n % 10];
		n /= 10;
	}

	return sum;
}

int countOfChains(int n) {
	vector<int> chains;
	vector<int>::iterator it;

	chains.push_back(n);
	while (1) {
		n = sumOfFactorialDigits(n);
		it = find(chains.begin(), chains.end(), n);
		if (it != chains.end()) {
			break;
		}
		chains.push_back(n);
	}

	return chains.size();
}

int main(int argc, char* argv[]) {
	int i, n, result;
	
	fillFactorials();
	
	result = 0;
	for (i = 0; i < 1000000; i++) {
		n = countOfChains(i);
		if (n == 60) {
			result++;
		}
		if (i % 10000 == 0) {
			cout << i << " : " << result << "\n";
		}
	}

	cout << result << "\n";
	
	return 0;
}
