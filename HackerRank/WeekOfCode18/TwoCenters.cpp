// https://www.hackerrank.com/contests/w18/challenges/two-centers

#include <iostream>
#include <queue>
#include <map>
#include <set>

using namespace std;

const int SIZE = 5000;

int maps[SIZE][SIZE] = {0, };
int dist[SIZE][SIZE] = {0, };
int link[SIZE] = {0, };
int p[SIZE] = {0, };
int m[SIZE] = {0, };
int visit[SIZE] = {0, };
int n;

void printMap() {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << dist[i][j] << "  ";
		}
		cout << "\n";
	}
}

void makeMap() {
	int x, y, k, root;
	queue<pair<int, int>> q;
	multimap<int, int> m;
	multimap<int, int>::iterator it;
	set<int> par, temp;

	root = 0;
	for (y = 0; y < link[root]; y++) {
		q.push(make_pair(maps[root][y], root));
	}
	visit[root] = 1;
	
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		p[y] = x;
		visit[y] = 1;
		for (k = 0; k < link[y]; k++) {
			if (visit[ maps[y][k] ] == 1) continue;
			q.push(make_pair(maps[y][k], y));
		}
	}

	par.clear();
	temp.clear();
	temp.insert(root);

	while (temp.size() > 0) {
		par = temp;
		temp.clear();
		for (y = 0; y < n; y++) {
			if (par.find(y) != par.end()) continue;
			x = p[y];
			if (par.find(x) == par.end()) continue;

			k = 1;
			while (true) {
				dist[x][y] = k;
				dist[y][x] = k;
				if (x == root) break;
				x = p[x];
				k++;
			}

			temp.insert(y);
			m.insert(make_pair(dist[root][y], y));
		}
	}

	for (it = m.begin(); it != m.end(); it++) {
		y = it->second;
		x = p[y];
		for (k = 0; k < n; k++) {
			if (y == k) continue;
			if (dist[y][k] != 0) continue;
			dist[y][k] = dist[x][k] + 1;
			dist[k][y] = dist[y][k];
		}
	}
}

int main(int argc, char* argv[]) {
	int i, j, k, x, y;

	cin >> n;

	i = n;
	while (--i) {
		cin >> x >> y;
		x--;
		y--;
		maps[x][ link[x] ] = y;
		maps[y][ link[y] ] = x;
		link[x]++;
		link[y]++;
	}

	makeMap();

	printMap();

	y = n;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (i == p[j] || j == p[i]) continue;
			x = 1;
			for (k = 0; k < n; k++) {
				if (dist[i][k] == 0 || dist[j][k] == 0) continue;
				if (dist[i][k] < dist[j][k]) {
					m[k] = dist[i][k];
				} else {
					m[k] = dist[j][k];
				}
				if (x < m[k]) x = m[k];
			}
			if (y > x) y = x;
		}
	}

	if (n == 2) {
		cout << "0\n";
	} else {
		cout << y << "\n";
	}

	return 0;
}

/*
5
1 2
2 3
3 4
4 5
=====
1
*/
