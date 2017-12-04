// Primality Test, Prime Number Test
// https://ko.wikipedia.org/wiki/밀러-라빈_소수판별법

#include<iostream>

using namespace std;

typedef long long INT64;

INT64 modmult(INT64 a, INT64 b, INT64 mod) {
  INT64 sum;

  if (a == 0 || b < mod / a) {
    return (a*b) % mod;
  }

  sum = 0;
  while (b > 0) {
    if (b & 1) sum = (sum + a) % mod;

    a = (2 * a) % mod;
    b >>= 1;
  }

  return sum;
}

INT64 modpow(INT64 a, INT64 b, INT64 mod) {
  INT64 product, pseq;

  product = 1;
  pseq = a % mod;
  while (b > 0) {
    if (b & 1) product = modmult(product, pseq, mod);

    pseq = modmult(pseq, pseq, mod);
    b >>= 1;
  }

  return product;
}

bool MillerRabin(INT64 n, int seed) {
  INT64 m, a;
  int i, k;

  if (n < 2) return false;
  if (n == 2) return true;
  if (!(n & 1)) return false;

  k = 0;
  m = n - 1;
  while (!(m & 1)) {
    m >>= 1;
    k++;
  }

  a = seed;
  a = modpow(a, m, n);
  if (a == 1 || a == n - 1) return true;
	
  for (i = 0; i < k - 1; i++) {
    a = modpow(a, 2, n);
    if (a == 1) return false;
    if (a == n - 1) return true;
  }

  return false;
}

bool primalityTest(INT64 n) {
  return MillerRabin(n, 2) && MillerRabin(n, 3) && MillerRabin(n, 5) && MillerRabin(n, 7) && MillerRabin(n, 11);
}

int main(int argc, char* arg[]) {
  INT64 n;
  int t;

  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    if (primalityTest(n) == true) {
      printf("Prime\n");
    } else {
      printf("Not prime\n");
    }
  }

  return 0;
}
