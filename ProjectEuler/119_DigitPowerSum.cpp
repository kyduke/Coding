// https://projecteuler.net/problem=119

#include <iostream>
#include <set>

using namespace std;

typedef unsigned long long UINT64;

const int LENGTH = 18;
const UINT64 LIMIT = 10000000000000000000;

set<UINT64> results;

int getDigitSum(UINT64 n) {
	int s;

	s = 0;
	while (n) {
		s += n % 10;
		n /= 10;
	}

	return s;
}

void calcPowerSum(int n) {
	UINT64 p, limit;
	int t;

	limit = LIMIT / n;

	p = n;
	while (p < limit) {
		p *= n;
		t = getDigitSum(p);
		if (t == n) results.insert(p);
	}
}

int main(int argc, char* argv[]) {
	set<UINT64>::iterator it;
	int n;

	for (n = 2; n < 9 * LENGTH; n++) {
		calcPowerSum(n);
	}

	cout << results.size() << "\n";
	n = 1;
	for (it = results.begin(); it != results.end(); it++, n++) {
		cout << n << ": " << *it << "\n";
	}

	return 0;
}
