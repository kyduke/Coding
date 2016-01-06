// https://www.hackerrank.com/challenges/bike-racers

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

typedef long long INT64;

using namespace std;

struct Coord {
	int x;
	int y;
};

struct Node {
	int racer;
	int bike;
	INT64 dist;
	bool operator< (const Node& a) const {
		return dist < a.dist;
	}
};

const int SIZE = 250;
const INT64 LIMIT = 200000000000000;

Coord racers[SIZE];
Coord bikes[SIZE];
Node data[SIZE * SIZE];
int map[SIZE][SIZE];
int matched[SIZE];
int visit[SIZE];
int n, m, k;

bool depthFirstSearch(int racer) {
	int bike;
	
	for (bike = 0; bike < m; bike++) {
		if (map[racer][bike] == 0 || visit[bike] == 1) continue;

		visit[bike] = 1;
		if (matched[bike] == -1 || depthFirstSearch(matched[bike]) == true) {
			matched[bike] = racer;
			return true;
		}
	}

	return false;
}

int countMatched(int x) {
	int i, racer, bike, ret;

	memset(map, 0, sizeof(int) * SIZE * SIZE);

	for (i = 0; i <= x; i++) {
		racer = data[i].racer;
		bike = data[i].bike;
		map[racer][bike] = 1;
	}

	memset(matched, -1, sizeof(int) * SIZE);

	ret = 0;
	for (racer = 0; racer < n; racer++) {
		memset(visit, 0, sizeof(int) * SIZE);
		if (depthFirstSearch(racer) == true) ret++;
	}

	return ret;
}

INT64 solve() {
	INT64 x, y;
	int i, j, idx, lo, hi, mid;

	idx = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			data[idx].racer = i;
			data[idx].bike = j;
			x = racers[i].x - bikes[j].x;
			y = racers[i].y - bikes[j].y;
			data[idx].dist = x * x + y * y;
			idx++;
		}
	}

	sort(data, data + idx);

	lo = -1;
	hi = idx;

	while (hi - lo > 1) {
		mid = (lo + hi) / 2;
		if (countMatched(mid) >= k) {
			hi = mid;
		} else {
			lo = mid;
		}
	}

	return data[hi].dist;
}

int main(int argc, char* argv[]) {
	int i;

	cin >> n >> m >> k;

	i = 0;
	while (i < n) {
		cin >> racers[i].x >> racers[i].y;
		i++;
	}

	i = 0;
	while (i < m) {
		cin >> bikes[i].x >> bikes[i].y;
		i++;
	}

	cout << solve() << "\n";

	return 0;
}

/*
3 3 2
0 1
0 2
0 3
100 1
200 2
300 3
=====
40000
*/
