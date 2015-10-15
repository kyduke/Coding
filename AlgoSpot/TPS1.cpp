// https://algospot.com/judge/problem/read/TSP1

#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

const int SIZE = 8;

double map[SIZE][SIZE];
int N;

class reverseOrder {
public:
	bool operator() (const pair<double, pair<int, int>>& lhs, const pair<double, pair<int, int>>& rhs) const {
		return (lhs.first > rhs.first);
	}
};

double solve() {
	priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, reverseOrder> q;
	int i, s, bit, mask, full;
	double min, dist;

	min = 100000.0;

	for (i = 0; i < N; i++) {
		q.push(make_pair(0.0, make_pair(1 << i, i)));
	}

	full = (1 << N) - 1;
	while (q.size()) {
		dist = q.top().first;
		mask = q.top().second.first;
		s = q.top().second.second;
		q.pop();
		if (dist > min) continue;
		if (full == mask) {
			if (min > dist) min = dist;
			continue;
		}
		for (i = 0; i < N; i++) {
			bit = 1 << i;
			if (mask & bit) continue;
			q.push(make_pair(dist +  map[s][i], make_pair(mask | bit, i)));
		}
	}

	return min;
}

int main(int argc, char* argv[]) {
	int C, i, j;

	cin >> C;
	while (C--) {
		cin >> N;
		j = 0;
		while (j < N) {
			i = 0;
			while (i < N) {
				cin >> map[j][i];
				i++;
			}
			j++;
		}
		printf("%.10f\n", solve());
	}

	return 0;
}

/*
2
3
0.0000000000  611.6157225201  648.7500617289
611.6157225201  0.0000000000  743.8557967501
648.7500617289  743.8557967501  0.0000000000
4
0.0000000000  326.0008994586  503.1066076077  290.0250922998
326.0008994586  0.0000000000  225.1785728436  395.4019367384
503.1066076077  225.1785728436  0.0000000000  620.3945520632
290.0250922998  395.4019367384  620.3945520632  0.0000000000
=====
1260.3657842490
841.2045646020
*/
