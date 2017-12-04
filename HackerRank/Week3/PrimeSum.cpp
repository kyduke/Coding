// https://www.hackerrank.com/contests/w3/challenges/prime-sum
// https://ko.wikipedia.org/wiki/밀러-라빈_소수판별법

#include<iostream>

using namespace std;

typedef long long INT64;

const int SIZE = 1000001;
int isPrime[SIZE] = {0, };

void findPrime() {
  int i, j;

  isPrime[0] = isPrime[1] = 1;
  for (i = 2; i * i < SIZE; i++) {
    if (isPrime[i] == 1) continue;
    for (j = i + i; j < SIZE; j += i) {
      isPrime[j] = 1;
    }
  }
}

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
  if (n < SIZE) {
    return !isPrime[n];
  } else {
    return MillerRabin(n, 2) && MillerRabin(n, 3) && MillerRabin(n, 5) && MillerRabin(n, 7) && MillerRabin(n, 11);
  }
}

bool solve(INT64 n, INT64 k) {
  if (k > 2) {
    if (n >= 4) {
      if (n % 2 == 0) {
        return k <= n / 2;
      } else {
        return (k - 1) <= (n - 3) / 2;
      }
    }
    return false;
  } else if (k == 2) {
    if (n % 2 == 0) {
      return n > 2;
    } else if (n > 2) {
      return primalityTest(n - 2);
    } else {
      return false;
    }
  } else {
    return primalityTest(n);
  }

  return false;
}

int main(int argc, char* arg[]) {
  INT64 n, k;
  int t;

  findPrime();

  scanf("%d", &t);
  while (t--) {
    scanf("%lld %lld", &n, &k);
    if (solve(n, k) == true) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }

  return 0;
}

/*
2
10 2
1 6
=====
Yes
No
*/

