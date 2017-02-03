// CodeFores 764 A.Taymyr is calling you
// http://codeforces.com/contest/764/problem/A

#include <iostream>

using namespace std;

int gcd (int a, int b){
  int c;

  while (a != 0) {
     c = a;
	 a = b % a;
	 b = c;
  }

  return b;
}

int solve(int n, int m, int z) {
	int a;

	a = n * m / gcd(n, m);

	return z / a;
}

int main(int argc, char* argv[]) {
	int n, m, z;

	cin >> n >> m >> z;

	cout << solve(n, m, z) << "\n";

	return 0;
}

/*
1 1 10
=====
10

1 2 5
=====
2

2 3 9
=====
1
*/
