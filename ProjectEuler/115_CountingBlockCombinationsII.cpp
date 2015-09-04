// https://projecteuler.net/problem=115

#include <iostream>
#include <string.h>

using namespace std;

typedef long long INT64;

const int LENGTH = 10000;

INT64 cache[LENGTH];

INT64 getCount(int m, int n) {
	int l, i;

	INT64& ret = cache[n];
	if (ret != -1) return ret;

	ret = 0;
	for (l = m; l <= n; l++) {
		for (i = 0; i < n - l + 1; i++) {
			ret += getCount(m, n - l - i - 1) + 1;
		}
	}

	return ret;
}

int main(int argc, char* argv[]) {
	int m, n;

	memset(cache, -1, sizeof(INT64) * LENGTH);

	m = 50;
	n = 50;
	while (n < LENGTH) {
		if (getCount(m, n) > 1000000) break;
		n++;
	}

	cout << n << ": " << getCount(m, n) + 1 << "\n";

	return 0;
}
