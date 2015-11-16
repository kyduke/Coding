// http://careercup.com/question?id=5726654544478208

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

UINT64 fibonacci(int n) {
	int k;
	UINT64 a, b, ret;

	if (n <= 2) return 1;

	k = n / 2;
	a = fibonacci(k + 1);
	b = fibonacci(k);

	if (n % 2 == 1) ret = a * a + b * b;
	else ret = b * (2 * a - b);

	return ret;
}

UINT64 casesOfReading(int n) {
	return fibonacci(n + 1);
}

int main(int argc, char* argv[]) {
	cout << casesOfReading(3) << "\n";
	cout << casesOfReading(5) << "\n";
	cout << casesOfReading(100) << "\n";

	return 0;
}
