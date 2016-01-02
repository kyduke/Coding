// http://codeforces.com/contest/608/problem/A

#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>> pq;

int solve() {
	int f, t, p, cost;

	cost = 0;
	p = pq.top().first;
	while (!pq.empty()) {
		f = pq.top().first;
		t = pq.top().second;
		pq.pop();
		cost += p - f;
		if (cost < t) cost = t;
		p = f;
	}

	return cost;
}

int main(int argc, char* argv[]) {
	int n, i, t;

	cin >> n >> i;
	pq.push(make_pair(i, 0));
	while (n--) {
		cin >> i >> t;
		pq.push(make_pair(i, t));
	}
	pq.push(make_pair(0, 0));

	cout << solve() << "\n";

	return 0;
}

/*
3 7
2 1
3 8
5 2
=====
11

5 10
2 77
3 33
8 21
9 12
10 64
=====
79
*/
