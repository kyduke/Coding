// http://codeforces.com/contest/721/problem/C

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 5001;

int map[SIZE][SIZE] = {0, };
vector<int> loads[SIZE];
vector<int> reverseLoads[SIZE];
int minDists[SIZE][SIZE] = {0, };

void findMinDist(int curr, int dest, int count, int dist) {
	int i, j;

	if (minDists[curr][count] == 0) {
		minDists[curr][count] = dist;
	} else if (minDists[curr][count] > dist) {
		minDists[curr][count] = dist;
	} else {
		return;
	}

	if (curr == dest) return;

	for (i = 0; i < loads[curr].size(); i++) {
		j = loads[curr][i];
		findMinDist(j, dest, count + 1, dist + map[curr][j]);
	}
}


void solve(int n, int limit) {
	vector<int> ans;
	int i, j, c, d, temp;

	findMinDist(1, n, 0, 0);

	for (i = n; i > 0; i--) {
		d = minDists[n][i];
		if (d > 0 && d <= limit) {
			c = i;
			break;
		}
	}

	ans.push_back(n);

	while (c > 1) {
		c--;
		for (i = 0; i < reverseLoads[n].size(); i++) {
			j = reverseLoads[n][i];
			temp = minDists[j][c];
			if (temp == d - map[j][n]) {
				n = j;
				d = temp;
				ans.push_back(n);
				break;
			}
		}
	}

	ans.push_back(1);

	cout << ans.size() << "\n";
	for (i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
}

int main(int argc, char* argv[]) {
	int n, m, a, b, t;
	int limit;

	cin >> n >> m >> limit;
	while (m--) {
		cin >> a >> b >> t;
		map[a][b] = t;
		loads[a].push_back(b);
		reverseLoads[b].push_back(a);
	}

	solve(n, limit);

	return 0;
}

/*
4 3 13
1 2 5
2 3 7
2 4 8
=====
3
1 2 4 

6 6 7
1 2 2
1 3 3
3 6 3
2 4 2
4 6 2
6 5 1
=====
4
1 2 4 6 

5 5 6
1 3 3
3 5 3
1 2 2
2 4 3
4 5 2
=====
3
1 3 5 

4 4 2
1 2 1
2 3 1
3 4 1
1 3 1
=====
3
1 3 4
*/
