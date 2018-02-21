// http://codeforces.com/contest/935/problem/C

#include <iostream>
#include <cmath>

using namespace std;

void solve(double r, double a, double b, double c, double d) {
	double l, s, t, x, y;

	s = a - c;
	t = b - d;
	if (r * r <= (s * s + t * t)) {
		printf("%.10f %.10f %.10f\n", a, b, r);
		return;
	}

	if (a == c) {
		x = a;
		if (b > d) {
			y = b + r;
			r = (y - d) / 2.0;
		} else {
			y = b - r;
			r = (d - y) / 2.0;
		}
		printf("%.10f %.10f %.10f\n", (x + c) / 2.0, (y + d) / 2.0, r);
		return;
	}

	if (b == d) {
		y = b;
		if (a > c) {
			x = a + r;
			r = (x - c) / 2.0;
		} else {
			x = a - r;
			r = (c - x) / 2.0;
		}
		printf("%.10f %.10f %.10f\n", (x + c) / 2.0, (y + d) / 2.0, r);
		return;
	}

	l = t / s;
	x = sqrt((r * r) / (1.0 + (l * l)));
	y = x * l;
	if (a > c) {
		x += a;
		y += b;
	} else {
		x = a - x;
		y = b - y;
	}
	s = x - c;
	t = y - d;
	r = sqrt((s * s) + (t * t)) / 2.0;
	printf("%.10f %.10f %.10f\n", (x + c) / 2.0, (y + d) / 2.0, r);
}

int main(int argc, char* argv[]) {
	int e;
	double r, a, b, c, d;

	scanf("%d", &e); r = e;
	scanf("%d", &e); a = e;
	scanf("%d", &e); b = e;
	scanf("%d", &e); c = e;
	scanf("%d", &e); d = e;

	solve(r, a, b, c, d);

	return 0;
}

/*
5 3 3 1 1
=====
3.7677669529663684 3.7677669529663684 3.914213562373095

10 5 5 5 15
=====
5.0 5.0 10.0
*/
