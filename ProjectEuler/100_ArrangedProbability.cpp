// https://projecteuler.net/problem=100

#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long UINT64;

UINT64 solve() {
	UINT64 b, btemp, n, ntemp, target;

	b = 15;
    n = 21;
	target = 1000000000000;
 
	while(n < target){
		btemp = 3 * b + 2 * n - 2;
		ntemp = 4 * b + 3 * n - 3;
 
		b = btemp;
		n = ntemp;
	}

	return b;
}

int main(int argc, char* argv[]) {
	UINT64 a, b, x;

	cout << solve() << "\n";

	return 0;
}
