// http://codeforces.com/problemset/problem/557/B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	int n, w, i, t, minGirl, minBoy, minCup;
	unsigned long long sumGirl, sumBoy, sum;
	vector<int> cups;

	cin >> n >> w;
	i = 0;
	while (i < n * 2) {
		cin >> t;
		cups.push_back(t);
		i++;
	}

	sort(cups.begin(), cups.end());

	minGirl = 1000000001;
	for (i = 0; i < n; i++) {
		minGirl = min(minGirl, cups[i]);
	}

	minBoy = 1000000001;
	for (i = n; i < n * 2; i++) {
		minBoy = min(minBoy, cups[i]);
	}

	minCup = min(minGirl * 2, minBoy);

	sumBoy = minCup * n;
	if (minCup % 2 == 1 && n % 2 == 1) {
		sumGirl = (minCup * (n - 1)) / 2;
		sum = sumBoy + sumGirl + minCup / 2;
		if (sum >= w) {
			cout << w << "\n";
		} else {
			cout << sum << ".5\n";
		}
	} else {
		sumGirl = (minCup * n) / 2;
		sum = sumGirl + sumBoy;
		if (sum > w) sum = w;
		cout << sum << "\n";
	}

	return 0;
}

/*
2 4
1 1 1 1
=====
3

3 18
4 4 4 2 2 2
=====
18

1 5
2 3
=====
4.5
*/
