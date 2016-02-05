// http://codeforces.com/problemset/problem/624/A

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int d, l, v1, v2;
	double answer;

	cin >> d >> l >> v1 >> v2;

	answer = (double)(l - d) / (v1 + v2);
	printf("%.6f\n", answer);

	return 0;
}

/*
2 6 2 2
=====
1.000000

1 9 1 2
=====
2.666667
*/
