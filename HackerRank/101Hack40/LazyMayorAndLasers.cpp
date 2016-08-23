// https://www.hackerrank.com/contests/101hack40/challenges/lazy-mayor-and-lasers

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long UINT64;

vector<int> heights;
vector<int> lasers;

UINT64 solve() {
	UINT64 sum;
	int i, j, k, p;

	sum = 0;

	sort(lasers.begin(), lasers.end(), greater<int>());
	p = lasers[0];
	for (j = p; j < heights.size(); j++) {
		sum += heights[j];
	}
	for (i = 1; i < lasers.size(); i++) {
		k = 1;
		for (j = p - 1; j >= lasers[i]; j--) {
			sum += min(k, heights[j]);
			k++;
		}
		p = lasers[i];
	}

	if (p > 0) {
		k = 1;
		for (j = p - 1; j >= 0; j--) {
			sum += min(k, heights[j]);
			k++;
		}
	}

	return sum;
}

int main(int argc, char* argv[]) {
	int n, i, a;

	cin >> n;
	heights.assign(n, 0);
	for (i = 0; i < n; i++) {
		cin >> heights[i];
	}

	cin >> n;
	lasers.assign(n, 0);
	for (i = 0; i < n; i++) {
		cin >> lasers[i];
		lasers[i]--;
	}

	cout << solve();

	return 0;
}

/*
5
3 1 4 5 1
2
3 5
=====
7

5
10 10 10 10 10
1
1
=====
50

5
10 10 10 10 10
2
1 5
=====
20

5
1 1 1 1 1
1
3
=====
5
*/
