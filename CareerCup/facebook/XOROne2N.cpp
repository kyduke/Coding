// http://careercup.com/question?id=5644130656976896

#include <iostream>

typedef unsigned long long UINT64;

using namespace std;

UINT64 getXOROne2N(UINT64 n) {
	switch (n % 4) {
		case 0: return n;
		case 1: return 1;
		case 2: return n + 1;
		case 3: return 0;
	}
	return 0;
}

int main(int argc, char* argv[]) {
	UINT64 i, a;

	a = 1;
	for (i = 2; i < 10000; i++) {
		a ^= i;
		cout << i << ": " << a << ", " << getXOROne2N(i) << "\n";
	}

	return 0;
}
