// https://codeforces.com/contest/1076/problem/C

#include <iostream>
#include <cmath>

using namespace std;


int main() {
	int t, n;
	double a, b, c;
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		
		if (n > 0 && n < 4) {
			printf("N\n");
			continue;
		}
		
		c = sqrt((double)(n * n - 4 * n));
		a = ((double)n + c) * 0.5;
		b = ((double)n - c) * 0.5;
		
		printf("Y ");
		printf("%.9f %.9f\n", a, b);
	}
	
	return 0;
}

/*
7
69
0
1
4
5
999
1000
=====
Y 67.985071301 1.014928699
Y 0.000000000 0.000000000
N
Y 2.000000000 2.000000000
Y 3.618033989 1.381966011
Y 997.998996990 1.001003010
Y 998.998997995 1.001002005
*/
