// http://codeforces.com/contest/722/problem/A

#include <iostream>

using namespace std;

char buffer[6];

void solve(int t) {
	int minHourDiff, minMinDiff, hour, minute, h, m, d, diff;

	minHourDiff = 3;
	minMinDiff = 3;
	if (t == 12) {
		for (h = 1; h <= 12; h++) {
			diff = 0;
			if (buffer[0] != ('0' + (h / 10))) diff++;
			if (buffer[1] != ('0' + (h % 10))) diff++;
			if (minHourDiff > diff) {
				minHourDiff = diff;
				hour = h;
			}
		}
	} else {
		for (h = 0; h <= 23; h++) {
			diff = 0;
			if (buffer[0] != ('0' + (h / 10))) diff++;
			if (buffer[1] != ('0' + (h % 10))) diff++;
			if (minHourDiff > diff) {
				minHourDiff = diff;
				hour = h;
			}
		}
	}
	for (m = 0; m <= 59; m++) {
		diff = 0;
		if (buffer[3] != ('0' + (m / 10))) diff++;
		if (buffer[4] != ('0' + (m % 10))) diff++;
		if (minMinDiff > diff) {
			minMinDiff = diff;
			minute = m;
		}
	}

	cout << hour / 10 << hour % 10 << ":" << minute / 10 << minute % 10;
}

int main(int argc, char* argv[]) {
	int t;

	cin >> t;
	cin >> buffer;

	solve(t);

	return 0;
}

/*
24
17:30
=====
17:30

12
17:30
=====
07:30

24
99:99
=====
09:09
*/
