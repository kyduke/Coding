// Google Code Jamp Round 1B 2016 Problem B. Close Match

#include <iostream>
#include <string>

using namespace std;

void solve(string a, string b) {
	string x, y;
	int i, comp;

	x = "";
	y = "";
	comp = 0;
	i = 0;
	while (i < a.size()) {
		if (comp == 0) {
			if (a[i] == '?' && b[i] == '?') {
				x += '0';
				y += '0';
			} else if (a[i] == '?' && b[i] != '?') {
				x += b[i];
				y += b[i];
			} else if (a[i] != '?' && b[i] == '?') {
				x += a[i];
				y += a[i];
			} else {
				x += a[i];
				y += b[i];
				if (a[i] > b[i]) {
					comp = 1;
				} else if (a[i] < b[i]) {
					comp = -1;
				}
			}
		} else if (comp == 1) {
			if (a[i] == '?') {
				x += '0';
			} else {
				x += a[i];
			}
			if (b[i] == '?') {
				y += '9';
			} else {
				y += b[i];
			}
		} else {
			if (a[i] == '?') {
				x += '9';
			} else {
				x += a[i];
			}
			if (b[i] == '?') {
				y += '0';
			} else {
				y += b[i];
			}
		}

		i++;
	}

	cout << x << " " << y;
}

int main(int argc, char* argv[]) {
	int T, t;
	string a, b;

	cin >> T;
	t = 0;
	while (t < T) {
		cin >> a >> b;
		t++;
		cout << "Case #" << t << ": ";
		solve(a, b);
		cout << "\n";
	}

	return 0;
}

/*
4
1? 2?
?2? ??3
? ?
?5 ?0
=====
Case #1: 19 20
Case #2: 023 023
Case #3: 0 0
Case #4: 05 00
*/
