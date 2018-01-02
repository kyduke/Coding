// Hacker Cup 2017 Round 1 B

#include <iostream>
#include <set>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 50;

UINT64 xpos[SIZE] = {0, };
UINT64 ypos[SIZE] = {0, };
int used[SIZE] = {0, };

int solve(int n, UINT64 r) {
	set<UINT64> xx, yy;
	set<UINT64>::iterator xit, yit;
	UINT64 xs, xe, ys, ye, xa, ya;
	int ans, i, cnt, temp;

	ans = 0;

	for (i = 0; i < n; i++) {
		xx.insert(xpos[i]);
		yy.insert(ypos[i]);
	}

	cnt = 0;
	for (xit = xx.begin(); xit != xx.end(); xit++) {
		xs = *xit;
		xe = xs + r;
		for (yit = yy.begin(); yit != yy.end(); yit++) {
			ys = *yit;
			ye = ys + r;
			temp = 0;
			for (i = 0; i < n; i++) {
				if (xs <= xpos[i] && xpos[i] <= xe && ys <= ypos[i] && ypos[i] <= ye) {
					temp++;
				}
			}
			if (cnt < temp) {
				cnt = temp;
				xa = xs;
				ya = ys;
			}
		}
	}

	ans += cnt;
	xs = xa;
	xe = xs + r;
	ys = ya;
	ye = ys + r;
	for (i = 0; i < n; i++) {
		if (xs <= xpos[i] && xpos[i] <= xe && ys <= ypos[i] && ypos[i] <= ye) {
			used[i] = 1;
		}
	}

	cnt = 0;
	for (xit = xx.begin(); xit != xx.end(); xit++) {
		xs = *xit;
		xe = xs + r;
		for (yit = yy.begin(); yit != yy.end(); yit++) {
			ys = *yit;
			ye = ys + r;
			temp = 0;
			for (i = 0; i < n; i++) {
				if (used[i] == 1) continue;
				if (xs <= xpos[i] && xpos[i] <= xe && ys <= ypos[i] && ypos[i] <= ye) {
					temp++;
				}
			}
			if (cnt < temp) {
				cnt = temp;
				xa = xs;
				ya = ys;
			}
		}
	}

	ans += cnt;

	return ans;
}

int main(int argc, char* argv[]) {
	UINT64 r;
	int t, ti, n, i;
	double p;

	cin >> t;
	for (ti = 1; ti <= t; ti++) {
		cin >> n >> r;

		for (i = 0; i < n; i++) {
			cin >> xpos[i] >> ypos[i];
			used[i] = 0;
		}

		cout << "Case #" << ti << ": " << solve(n, r);
		if (ti < t) cout << "\n";
	}

	return 0;
}
