// Modulo Inverse
// http://kwony91.tistory.com/m/entry/%EB%AA%A8%EB%93%88%EB%9F%AC-%EB%82%98%EB%88%97%EC%85%88-%EC%97%B0%EC%82%B0-%EC%B2%98%EB%A6%AC%ED%95%98%EA%B8%B0

#include <iostream>

using namespace std;

typedef long long INT64;

const INT64 MOD = 1000000007;

INT64 moduloInverse(INT64 k, INT64 p, INT64 m) {
	INT64 ans, half;

	if (p == 0) return 1;
	if (p == 1) return k;

	half = moduloInverse(k, p / 2, m);
	ans = (half * half) % m;
	if (p % 2 == 1) {
		ans = (ans * k) % m;
	}

	return ans;
}

INT64 divideModuloWithModuloInverse(INT64 n, INT64 k) {
	return ((n % MOD) * moduloInverse(k, MOD - 2, MOD)) % MOD;
}

INT64 simpleDivideModulo(INT64 n, INT64 k) {
	return (n / k) % MOD;
}

int main(int argc, char** argv) {
	INT64 n, k;

	k = 49;
	n = k * 1203;
	cout << n << " / " << k << " = " << simpleDivideModulo(n, k) << " , " << divideModuloWithModuloInverse(n, k) << "\n";

	k = 129749;
	n = k * 1208777303;
	cout << n << " / " << k << " = " << simpleDivideModulo(n, k) << " , " << divideModuloWithModuloInverse(n, k) << "\n";

	k = 129987749;
	n = k * 2777754303;
	cout << n << " / " << k << " = " << simpleDivideModulo(n, k) << " , " << divideModuloWithModuloInverse(n, k) << "\n";

	return 0;
}
