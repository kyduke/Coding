// http://codeforces.com/problemset/problem/591/A

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	double l, p, q;

	scanf("%lf", &l);
	scanf("%lf", &p);
	scanf("%lf", &q);
	q += p;
	printf("%.5f\n", l * p / q);

	return 0;
}

/*
100
50
50
=====
50

199
60
40
=====
119.4
*/
