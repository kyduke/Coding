// nCr
// Combination recursion
// Pascal triangle
// nCr = (n - 1)C(r - 1) + (n - 1)Cr
// https://en.wikipedia.org/wiki/Combination
// https://en.wikipedia.org/wiki/Pascal%27s_triangle

#include <iostream>
#include <map>

using namespace std;

typedef unsigned long long UINT64;

const UINT64 MUL = 1000000000;

map<UINT64, int> cache;

int ncr(UINT64 n, UINT64 r) {
	map<UINT64, int>::iterator it;
	UINT64 k;
	int v;

	r = min(r, n - r);

	if (r == 0) {
		return 1;
	} else if (r == 1) {
		return n;
	}

	k = n * MUL + r;
	it = cache.find(k);
	if (it != cache.end()) {
		return it->second;
	}

	v = ncr(n - 1, r - 1) + ncr(n - 1, r);
	cache.insert(make_pair(k, v));

	return v;
}

int main(int argc, char* argv[]) {
	int i, j;

	for (i = 0; i < 10; i++) {
		for (j = 0; j <= i; j++) {
			cout << ncr(i, j) << " ";
		}
		cout << "\n";
	}

	return 0;
}
