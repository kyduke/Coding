// https://algospot.com/judge/problem/read/LUNCHBOX

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int microwaves[10000];
int eats[10000];
int N;

int solve() {
	vector<pair<int, int>> lunchBoxes;
	vector<pair<int, int>>::reverse_iterator it;
	int result;
	int i, sumOfMicrowave;

	for (i = 0; i < N; i++) {
		lunchBoxes.push_back(make_pair(eats[i], microwaves[i]));
	}

	sort(lunchBoxes.begin(), lunchBoxes.end());

	result = 0;
	sumOfMicrowave = 0;
	for (it = lunchBoxes.rbegin(); it != lunchBoxes.rend(); it++) {
		sumOfMicrowave += it->second;
		result = max(result, sumOfMicrowave + it->first);
	}

	return result;
}

int main(int argc, char* argv[]) {
	int T;
	int i;

	cin >> T;
	while (T--) {
		cin >> N;
		i = 0;
		while (i < N) {
			cin >> microwaves[i++];
		}
		i = 0;
		while (i < N) {
			cin >> eats[i++];
		}

		cout << solve() << "\n";
	}

	return 0;
}

/*
2
3
2 2 2
2 2 2
3
1 2 3
1 2 1
=====
8
7
*/
