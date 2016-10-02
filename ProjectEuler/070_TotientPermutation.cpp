//https://projecteuler.net/problem=70

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

const int MAX = 10000000;
const int SQRT = 5000;

int primes[MAX];
vector<int> p;

void findPrimes() {
	int i, j;

	memset(primes, 0, sizeof(primes));

	for (i = 2; i < SQRT; i++) {
		if (primes[i] == 1) continue;
		p.push_back(i);
		j = i + i;
		while (j < SQRT) {
			primes[j] = 1;
			j += i;
		}
	}
}

void convertNumber(int n, int (&pNum)[11]) {
	int i;

	memset(pNum, 0, sizeof(int) * 11);

	while (n) {
		pNum[0]++;
		pNum[(n % 10) + 1]++;
		n /= 10;
	}
}

bool isSamePNum(int x, int y) {
	int a[11], b[11];
	int i;

	convertNumber(x, a);
	convertNumber(y, b);

	for (i = 0; i < 11; i++) {
		if (a[i] != b[i]) return false;
	}

	return true;
}

void solve() {
	int i, j, n, best, phi, bestPhi;
	double ratio, bestRatio;

	best = 1;
	bestPhi = 1;
	bestRatio = 2.0;

	for (i = 0; i < p.size(); i++) {
		for (j = i + 1; j < p.size(); j++) {
			n = p[i] * p[j];
			if (n > MAX) break;

			phi = (p[i] - 1) * (p[j] - 1);
			ratio = (double)n / phi;
			if (isSamePNum(n, phi) == true && bestRatio > ratio) {
				best = n;
				bestPhi = phi;
				bestRatio = ratio;
			}
		}
	}

	cout << best << "\n";
	cout << bestPhi << "\n";
	cout << bestRatio << "\n";
}

int main(int argc, char* argv[]) {

	findPrimes();

	solve();

	return 0;
}
