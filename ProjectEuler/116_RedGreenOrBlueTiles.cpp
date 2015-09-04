// https://projecteuler.net/problem=116

#include <iostream>
#include <string.h>

using namespace std;

typedef long long INT64;

const int COLORS = 5;
const int LENGTH = 10000;

INT64 cache[COLORS][LENGTH];

INT64 getCount(int m, int n) {
	int l, i;

	INT64& ret = cache[m][n];
	if (ret != -1) return ret;

	ret = 0;
	for (i = 0; i < n - m + 1; i++) {
		ret += getCount(m, n - m - i) + 1;
	}

	return ret;
}

int main(int argc, char* argv[]) {
	int m, n;
	INT64 count;

	memset(cache, -1, sizeof(INT64) * COLORS * LENGTH);

	count = 0;
	n = 50;
	for (m = 2; m < 5; m++) {
		count += getCount(m, n);
	}

	cout << n << ": " << count << "\n";

	return 0;
}
