// https://algospot.com/judge/problem/read/MATCHORDER

#include <iostream>
#include <set>

using namespace std;

int guest[100];
multiset<int> home;
int N;

int solve() {
	int result;
	int i;

	result = 0;

	for (i = 0; i < N; i++) {
		if (guest[i] > *home.rbegin()) {
			home.erase(home.begin());
		} else {
			if (*home.lower_bound(guest[i]) == guest[i]) {
				home.erase(home.lower_bound(guest[i]));
			} else {
				home.erase(home.upper_bound(guest[i]));
			}
			result++;
		}
	}

	return result;
}

int main(int argc, char* argv[]) {
	int C;
	int i, t;

	cin >> C;
	while (C--) {
		cin >> N;
		i = 0;
		while (i < N) {
			cin >> guest[i++];
		}
		i = 0;
		while (i < N) {
			cin >> t;
			home.insert(t);
			i++;
		}

		cout << solve() << "\n";
	}
}

/*
3
6
3000 2700 2800 2200 2500 1900
2800 2750 2995 1800 2600 2000
3
1 2 3
3 2 1
4
2 3 4 5
1 2 3 4
=====
5
3
3
*/
