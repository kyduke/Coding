// CodeForces 764 D.Timofey and rectangles
// http://codeforces.com/contest/764/problem/D

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int SIZE = 500000;

vector<int> links[SIZE];
int rects[SIZE][4];
int colors[SIZE] = {0, };

void solveMySolution(int n) {
	queue<int> q;
	int i, j, k;
	bool c1, c2, c3, c4;

	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (rects[i][0] == rects[j][2]) {
				if (rects[i][1] < rects[j][3] && rects[i][3] > rects[j][1]) {
					links[i].push_back(j);
					links[j].push_back(i);
				}
			} else if (rects[i][1] == rects[j][3]) {
				if (rects[i][0] < rects[j][2] && rects[i][2] > rects[j][0]) {
					links[i].push_back(j);
					links[j].push_back(i);
				}
			} else if (rects[i][2] == rects[j][0]) {
				if (rects[i][1] < rects[j][3] && rects[i][3] > rects[j][1]) {
					links[i].push_back(j);
					links[j].push_back(i);
				}
			} else if (rects[i][3] == rects[j][1]) {
				if (rects[i][0] < rects[j][2] && rects[i][2] > rects[j][0]) {
					links[i].push_back(j);
					links[j].push_back(i);
				}
			}
		}
	}

	for (i = 0; i < n; i++) {
		if (colors[i] != 0) continue;
		q.push(i);
		while (!q.empty()) {
			k = q.front();
			q.pop();
			if (colors[k] != 0) continue;
			c1 = c2 = c3 = c4 = false;
			for (j = 0; j < links[k].size(); j++) {
				switch (colors[ links[k][j] ]) {
					case 0: q.push(links[k][j]); break;
					case 1: c1 = true; break;
					case 2: c2 = true; break;
					case 3: c3 = true; break;
					case 4: c4 = true; break;
				}
			}
			if (c1 == false) {
				colors[k] = 1;
			} else if (c2 == false) {
				colors[k] = 2;
			} else if (c3 == false) {
				colors[k] = 3;
			} else if (c4 == false) {
				colors[k] = 4;
			}
		}
	}
}

void solve(int n) {
	int i, x, y;

	for (i = 0; i < n; i++) {
		x = rects[i][0];
		y = rects[i][1];
		colors[i] = ((500000000 + 2 * (x % 2) + (y % 2)) % 4) + 1;
	}
}

int main(int argc, char* argv[]) {
	int n, i;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> rects[i][0] >> rects[i][1] >> rects[i][2] >> rects[i][3];
	}

	solve(n);

	cout << "YES\n";
	for (i = 0; i < n; i++) {
		cout << colors[i] << "\n";
	}

	return 0;
}

/*
8
0 0 5 3
2 -1 5 0
-3 -4 2 -1
-1 -1 2 0
-3 0 0 5
5 2 10 3
7 -3 10 2
4 -2 7 -1
=====
YES
1
2
2
3
2
2
4
1
*/
