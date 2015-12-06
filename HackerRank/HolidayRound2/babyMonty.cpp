// https://www.hackerrank.com/contests/round-2-holiday-cup/challenges/baby-monty-and-interview

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

const int SIZE = 10000;

int d[SIZE];
int v[SIZE];

int main(int argc, char* argv[]) {
	vector<vector<int>> links;
	vector<int> vv;
	queue<int> q;
	int t, n, x, y, i, j, k;

	cin >> t;
	while (t--) {
		cin >> n;
		memset(d, 0, sizeof(int) * n);
		memset(v, 0, sizeof(int) * n);

		vv.clear();
		links.clear();

		for (i = 0; i < n; i++) {
			links.push_back(vv);
		}

		for (i = 0; i < n - 1; i++) {
			cin >> x >> y;
			x--;
			y--;
			links[x].push_back(y);
			links[y].push_back(x);
		}

		q.push(0);
		v[0] = 1;
		while (!q.empty()) {
			x = q.front();
			q.pop();
			for (i = 0; i < links[x].size(); i++) {
				y = links[x][i];
				if (v[y] == 1) continue;
				q.push(y);
				v[y] = 1;
				d[y] = d[x] + 1;
			}
		}

		x = 0;
		y = 0;
		for (i = 0; i < n; i++) {
			if (d[i] % 2 == 0) {
				x++;
			} else {
				y++;
			}
		}

		cout << ((x * (x - 1)) + (y * (y - 1))) / 2 << "\n";
	}

	return 0;
}

/*
1  
5  
1 2  
1 3  
2 4  
3 5 
=====
4
*/
