// http://codeforces.com/contest/932/problem/C

#include <iostream>

using namespace std;

void solve(int n, int a, int b) {
  int i, j, l, m, cntA, cntB;

  cntA = -1;
  cntB = -1;

  l = n / a;
  for (i = 0; i <= l; i++) {
    m = n - a * i;
    if (m % b == 0) {
      cntA = i;
      cntB = m / b;
      break;
    }
  }

  if (cntA < 0) {
    printf("-1\n");
    return;
  }

  for (i = 1; i <= cntA; i++) {
    m = i * a;
    printf("%d ", m);
    for (j = m - a + 1; j < m; j++) {
      printf("%d ", j);
    }
  }
  for (i = 1; i <= cntB; i++) {
    m = cntA * a + i * b;
    printf("%d ", m);
    for (j = m - b + 1; j < m; j++) {
      printf("%d ", j);
    }
  }
  printf("\n");
}

int main(int argc, char* argv[]) {
  int n, a, b;

  scanf("%d %d %d", &n, &a, &b);
  solve(n, a, b);

  return 0;
}

/*
9 2 5
=====
6 5 8 3 4 1 9 2 7

3 2 1
=====
1 2 3 
*/
