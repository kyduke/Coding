// https://algospot.com/judge/problem/read/ITES

#include <iostream>
#include <queue>

typedef unsigned long long UINT64;

using namespace std;

unsigned int getNextSignal(unsigned int seed) {
	unsigned int ret;

	ret = seed * 214013 + 2531011;

	return ret;
}

int solve(int k, int n) {
	queue<int> q;
	UINT64 sum;
	unsigned int seed;
	int i, s, ans;

	ans = 0;
	seed = 1983;
	sum = 0;
	for (i = 0; i < n; i++) {
		s = (seed % 10000) + 1;
		q.push(s);
		sum += s;

		while (sum > k) {
			sum -= q.front();
			q.pop();
		}

		if (sum == k) ans++;

		seed = getNextSignal(seed);
	}

	return ans;
}

int main(int argc, char* argv[]) {
	int c, k, n;

	cin >> c;
	while (c--) {
		cin >> k >> n;
		cout << solve(k, n) << "\n";
	}

	return 0;
}

/*
3
8791 20
5265 5000
3578452 5000000
=====
1
4
1049
*/
