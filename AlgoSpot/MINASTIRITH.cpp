// https://algospot.com/judge/problem/read/MINASTIRITH

#include <iostream>
#include <map>
#include <math.h>

using namespace std;

multimap<double, double> spots;
const double PI2 = atan(1.0) * 8.0;

int getNextRange(double last, double start) {
	multimap<double, double>::iterator it;
	double nextStart;

	if (start >= last) return 0;

	nextStart = -1.0;
	for (it = spots.begin(); it != spots.end(); it++) {
		if (it->first > start) break;
		if (it->second <= start) continue;
		if (nextStart < it->second) nextStart = it->second;
	}

	if (nextStart == -1.0) return 1000;

	return getNextRange(last, nextStart) + 1;
}

int solve() {
	int result;
	multimap<double, double>::iterator it;

	result = 1000;

	for (it = spots.begin(); it != spots.end(); it++) {
		if (it->first > 0) break;
		result = min(result, getNextRange(it->first + PI2, it->second) + 1);
	}

	return result;
}

int main(int argc, char* argv[]) {
	int c, n;
	double x, y, r, t, s, e;
	bool one;

	cin >> c;
	while (c--) {
		spots.clear();
		one = false;
		cin >> n;
		while (n--) {
			cin >> x >> y >> r;
			if (r >= 16.0) one = true;
			if (one == false) {
				s = atan2(x, y);
				if (s < 0.0) s += PI2;
				t = asin(r / 16.0) * 2.0;
				if (t < 0.0) t += PI2;
				e = s + t;
				s = s - t;
				if (s > 0.0 && e >= PI2) {
					s -= PI2;
					e -= PI2;
				}
				spots.insert(make_pair(s, e));
			}
		}

		if (one == false) {
			n = solve();
			if (n >= 1000) {
				cout << "IMPOSSIBLE\n";
			} else {
				cout << n << "\n";
			}
		} else {
			cout << "1\n";
		}
	}

	return 0;
}

/*
3
10
7.02066050 -3.83540431 4.0
-7.23257714 -3.41903904 2.0
0.00000000 -8.00000000 8.0
-8.00000000 -0.00000000 4.8
-6.47213595 4.70228202 3.2
-4.70228202 6.47213595 4.8
7.60845213 -2.47213595 1.6
-2.47213595 -7.60845213 8.8
6.47213595 4.70228202 7.6
-0.00000000 8.00000000 4.8
4
8.00000000 0.00000000 8.00
0.00000000 -8.00000000 8.00
-8.00000000 -0.00000000 8.00
1.25147572 7.90150672 5.40
1
8 0 15.99
=====
5
4
IMPOSSIBLE
*/
