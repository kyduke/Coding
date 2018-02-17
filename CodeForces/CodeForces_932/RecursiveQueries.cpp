// http://codeforces.com/contest/932/problem/B

#include <iostream>

using namespace std;

const int SIZE = 1000001;

int dp[SIZE] = {0, };
int sum[10][SIZE] = {0, };

int digitMultiply(int n) {
  int ans, k;

  if (dp[n] != 0) return dp[n];

  k = n;
  ans = 1;
  while (k) {
    if (k % 10 != 0) ans *= k % 10;
    k /= 10;
  }
  
  ans = digitMultiply(ans);
  dp[n] = ans;

  return ans;
}

void preCalc() {
  int i, j, n;

  for (i = 1; i < 10; i++) dp[i] = i;

  for (i = 10; i < SIZE; i++) {
    digitMultiply(i);
  }
  
  for (i = 1; i < SIZE; i++) {
    for (j = 1; j < 10; j++) {
      sum[j][i] = sum[j][i - 1];
    }
    sum[ dp[i] ][i]++;
  }
}

int main(int argc, char* argv[]) {
  int q, l, r, k;

  preCalc();

  scanf("%d", &q);
  while (q--) {  
   scanf("%d %d %d", &l, &r, &k);
   printf("%d\n", sum[k][r] - sum[k][l - 1]);
  }

  return 0;
}

/*
4
22 73 9
45 64 6
47 55 7
2 62 4
=====
1
4
0
8

4
82 94 6
56 67 4
28 59 9
39 74 4
=====
3
1
1
5
*/
