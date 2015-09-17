// http://www.careercup.com/question?id=5690448221831168

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primes;

void initPrime(int a) {
	int i, j, l;
	bool p;

	l = (int)sqrt((double)a);
	for (i = 2; i <= a; i++) {
		p = true;
		for (j = 0; j < primes.size(); j++) {
			if (i % primes[j] == 0) {
				p = false;
				break;
			}
		}
		if (p) primes.push_back(i);
	}
}

bool isPrime(int n) {
	int i, l;

	if (n < 2) return false;

	l = (int)sqrt((double)n);
	for (i = 0; i < primes.size(); i++) {
		if (l < primes[i]) break;
		if (n % primes[i] == 0) return false;
	}
	primes.push_back(n);

	return true;
}

int solve(int a, int n) {
	initPrime(a);

	while (n) {
		if (isPrime(++a)) n--;
	}

	return a;
}

int main(int argc, char* argv[]) {
	int a, n;

	cin >> a >> n;
	cout << solve(a, n) << "\n";

	return 0;
}
