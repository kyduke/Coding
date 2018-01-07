// http://codeforces.com/contest/912/problem/B

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

int main(int argc, char* argv[]) {
  UINT64 n, k;

  scanf("%I64u %I64u", &n, &k);

  if (k == 1) {
    k = n;
  } else {
    k = 1;
    while (k < n) {
      k = k * 2 + 1;
    }
  }

  printf("%I64u\n", k);

  return 0;
}

/*
4 3
=====
7

6 6
=====
7
*/

/*
912B - New Year's Eve
If k = 1, the answer is n.

Otherwise, let's take a look at the most significant bit of answer and denote it by p
(with the 0-th bit being the least possible). It must be the same as the most significant
bit of n. This means the answer cannot exceed 2^(p + 1) - 1.

Consider the numbers 2^p and 2^p - 1. Obviously, they both do not exceed n. At the same time,
their xor is 2^(p + 1) - 1. Hence, the maximum answer can always be obtained if k > 1.
*/
