// https://projecteuler.net/problem=117

#include <iostream>
#include <string.h>

using namespace std;

typedef long long INT64;

const int LENGTH = 10000;

INT64 cache[LENGTH];

INT64 getCount(int n) {
	int l, i;

	INT64& ret = cache[n];
	if (ret != -1) return ret;

	ret = 0;
	for (l = 2; l < 5; l++) {
		for (i = 0; i < n - l + 1; i++) {
			ret += getCount(n - l - i) + 1;
		}
	}

	return ret;
}

int main(int argc, char* argv[]) {
	int n;

	memset(cache, -1, sizeof(INT64) * LENGTH);

	n = 50;
	cout << n << ": " << getCount(n) + 1 << "\n";

	return 0;
}
