// Facebook HackerCup 2017 A

#include <iostream>

using namespace std;

const double PI = 3.141592653589793;
const int DISTANCE = 2500;

void solve(double p, int x, int y) {
	int distance;
	double angle, progress, a, b;

	if (p == 0.0) {
		cout << "white";
		return;
	}

	if (x == 50 && y == 50) {
		cout << "black";
		return;
	}

	distance = (x - 50) * (x - 50) + (y - 50) * (y - 50);
	if (distance > DISTANCE) {
		cout << "white";
		return;
	}

	angle = (p / 50.0) * PI;

	/*
	flip y
	| 1  0 | | x | = |  x |
	| 0 -1 | | y |   | -y |

	rotate 90
	| 0 -1 | | x | = | -y |
	| 1  0 | | y |   |  x |
	*/
	a = (double)(y - 50);
	b = (double)(x - 50);

	progress = atan2(b, a);

	if (progress < 0.0) {
		progress = progress + PI + PI;
	}

	if (progress > angle) {
		cout << "white";
	} else {
		cout << "black";
	}
}

int main(int argc, char* argv[]) {
	int t, ti, x, y;
	double p;

	cin >> t;
	for (ti = 1; ti <= t; ti++) {
		cin >> p >> x >> y;

		cout << "Case #" << ti << ": ";
		solve(p, x, y);
		if (ti < t) cout << "\n";
	}

	return 0;
}

/*
5
0 55 55
12 55 55
13 55 55
99 99 99
87 20 40
=====
Case #1: white
Case #2: white
Case #3: black
Case #4: white
Case #5: black
*/
