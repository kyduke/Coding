// https://algospot.com/judge/problem/read/WEEKLYCALENDAR

#include <iostream>
#include <string>

using namespace std;

void solve(int m, int d, string w) {
	int ends[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string ws[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int i, t, k;

	for (t = 0; t < 7; t++) {
		if (w == ws[t]) break;
	}

	for (i = 0; i < 7; i++) {
		k = d + i - t;
		if (k <= 0) {
			k += ends[(m - 1 + 12) % 12];
		} else if (k > ends[m]) {
			k -= ends[m];
		}
		cout << k << " ";
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	int T, t, m, d;
	string w;

	cin >> T;
	t = 0;
	while (t < T) {
		cin >> m >> d >> w;
		solve(m - 1, d, w);
		t++;
	}

	return 0;
}

/*
5
7 27 Saturday
7 27 Sunday
7 28 Sunday
7 28 Monday
7 29 Tuesday
=====
21 22 23 24 25 26 27
27 28 29 30 31 1 2
28 29 30 31 1 2 3
27 28 29 30 31 1 2
27 28 29 30 31 1 2
*/
