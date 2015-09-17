// http://codeforces.com/problemset/problem/578/A

#include <iostream>
#include <stdio.h>

using namespace std;

double findPlusSlope(double a, double b) {
	double x, t, ret;
	int i, j, m;

	x = a - b;
	ret = -1.0;
	
	if (x < 0) return ret;
	if (x == 0.0) return b;

	i = 2;
	t = x / i;
	while (t >= b) {
		ret = t;
		i *= 2;
		t = x / i;
	}

	j = i / 2;
	i -= 2;
	while (j <= i) {
		m = (i - j) / 2 + j;
		if (m % 2 == 1) m++;
		t = x / m;
		if (t >= b) {
			j = m;
			ret = t;
			if (i == j) break;
		} else {
			i = m - 2;
		}
	}

	return ret;
}

double findMinusSlope(double a, double b) {
	double x, t, ret;
	int i, j, m;

	x = a + b;
	ret = -1.0;
	
	if (x <= 0) return ret;
	if ((x / 2) < b) return ret;

	i = 2;
	t = x / i;
	while (t >= b) {
		ret = t;
		i *= 2;
		t = x / i;
	}

	j = i / 2;
	i -= 2;
	while (j <= i) {
		m = (i - j) / 2 + j;
		if (m % 2 == 1) m++;
		t = x / m;
		if (t >= b) {
			j = m;
			ret = t;
			if (i == j) break;
		} else {
			i = m - 2;
		}
	}

	return ret;
}

void solve(int a, int b) {
	double retPlus, retMinus;

	retPlus = findPlusSlope((double)a, (double)b);
	retMinus = findMinusSlope((double)a, (double)b);

	if (retPlus < 0.0 && retMinus < 0.0) {
		cout << "-1\n";
	} else if (retPlus < 0.0) {
		printf("%0.12f\n", retMinus);
	} else if (retMinus < 0.0) {
		printf("%0.12f\n", retPlus);
	} else {
		if (retPlus < retMinus) {
			printf("%0.12f\n", retPlus);
		} else {
			printf("%0.12f\n", retMinus);
		}
	}
}

int main(int argc, char* argv[]) {
	int a, b;

	cin >> a >> b;

	solve(a, b);

	return 0;
}

/*
3 1
=====
1.000000000000

1 3
=====
-1

4 1
=====
1.250000000000
*/
