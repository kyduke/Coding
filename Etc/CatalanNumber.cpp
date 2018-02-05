// Catalan Number
// https://en.wikipedia.org/wiki/Catalan_number
// https://ko.wikipedia.org/wiki/%EC%B9%B4%ED%83%88%EB%9E%91_%EC%88%98

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

	if (r == 0 || n == r) {
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

int catalan(int n) {
	return ncr(n + n, n) / (n + 1);
}


int main(int argc, char* argv[]) {
	int i;

	for (i = 0; i < 10; i++) {
		cout << i << ": " << catalan(i) << "\n";
	}

	return 0;
}

/*
1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862
*/
