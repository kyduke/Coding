// https://code.google.com/codejam/contest/10214486/dashboard#s=p0

#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

const int MAX_COST = 999999999;
const int CITIES = 500;
const int ROADS = 2000;

struct Road {
	int x;
	int y;
	int costs[24];
};

struct CityJob {
	int cost;
	int city;
	int hour;
	int road;
	CityJob(int c, int i, int s, int r) : cost(c), city(i), hour(s), road(r) {}
	bool operator<(const CityJob& a) const {
		return cost > a.cost;
	}
};

int map[CITIES][CITIES];
vector<int> cities[CITIES];
Road roads[ROADS];
int N;

bool connect(int d) {
	vector<int> visit;
	queue<int> q;
	int i, k;

	visit.assign(N, 0);
	visit[0] = 1;
	q.push(0);
	while (!q.empty()) {
		k = q.front();
		q.pop();
		if (k == d) return true;
		for (i = 0; i < N; i++) {
			if (visit[i] == 1) continue;
			if (map[k][i] == 0) continue;
			visit[i] = 1;
			q.push(i);
		}
	}

	return false;
}

int minCost(int d, int s) {
	priority_queue<CityJob> job;
	int cost, i, k, c, r, nextRoad, nextCity;

	if (connect(d) == false) return -1;

	cost = MAX_COST;
	job.push(CityJob(0, 0, s, -1));
	while (!job.empty()) {
		c = job.top().cost;
		k = job.top().city;
		s = job.top().hour;
		r = job.top().road;
		job.pop();
		if (k == d) {
			if (cost > c) {
				cost = c;
			}
			continue;
		}

		if (cost <= c) break;

		for (i = 0; i < cities[k].size(); i++) {
			if (cities[k][i] == r) continue;
			nextRoad = cities[k][i];
			if (roads[nextRoad].x == k) {
				nextCity = roads[nextRoad].y;
			} else {
				nextCity = roads[nextRoad].x;
			}
			if (nextCity == 0) continue;
			job.push(CityJob(c + roads[nextRoad].costs[s], nextCity, (s + roads[nextRoad].costs[s]) % 24, nextRoad));
		}
	}

	if (cost == MAX_COST) cost = -1;

	return cost;
}

int main(int argc, char* argv[]) {
	int T, M, K, x, y, i, t, d, s, c;

	freopen("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	cin >> T;
	c = 0;
	while (c < T) {
		cin >> N >> M >> K;
		
		for (x = 0; x < N; x++) {
			cities[x].clear();
			for (y = 0; y < N; y++) {
				map[x][y] = 0;
			}
		}

		d = 0;
		while (d < M) {
			cin >> x >> y;
			x--;
			y--;
			cities[x].push_back(d);
			cities[y].push_back(d);
			map[x][y] = 1;
			map[y][x] = 1;
			roads[d].x = x;
			roads[d].y = y;
			i = 0;
			while (i < 24) {
				cin >> t;
				roads[d].costs[i] = t;
				i++;
			}
			d++;
		}

		c++;
		cout << "Case #" << c << ":";

		while (K--) {
			cin >> d >> s;
			cout << " " << minCost(d - 1, s);
		}

		cout << "\n";
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}

/*
3
3 3 2
1 2
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 3
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
2 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
2 1
3 3
3 1 2
1 2
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
2 2
3 4
3 3 3
1 2
7 23 23 25 26 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8
1 3
10 11 15 26 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11
2 3
7 29 28 27 26 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8
2 14
3 3
3 21
=====
Case #1: 1 2
Case #2: 1 -1
Case #3: 17 26 13
*/
