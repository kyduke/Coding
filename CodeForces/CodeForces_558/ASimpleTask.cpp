// http://codeforces.com/problemset/problem/558/E
// A Simple Task
// Time limit exceeded on test 9

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char buffer[100001];
vector<pair<int, pair<int, int>>> queries;

bool decendantFunc (char a, char b) {
	return (a > b);
}

void sortString() {
	vector<pair<int, pair<int, int>>>::iterator it;
	int i, j, k;
	for (it = queries.begin(); it != queries.end(); it++) {
		i = it->first;
		j = it->second.first;
		k = it->second.second;
		if (k == 1) {
			sort(buffer + i - 1, buffer + j);
		} else if (k == 0) {
			sort(buffer + i - 1, buffer + j, decendantFunc);
		}
	}
}

int main(int argc, char* argv[]) {
	int n, q, i, j, k;
	int minRange, maxRange;

	cin >> n >> q;
	cin >> buffer;
	minRange = -1;
	while (q--) {
		cin >> i >> j >> k;
		if (minRange == -1) {
			minRange = i;
			maxRange = j;
		} else if (i <= minRange && j >= maxRange) {
			queries.clear();
		}
		queries.push_back(make_pair(i, make_pair(j, k)));
		minRange = min(minRange, i);
		maxRange = max(maxRange, j);
	}

	sortString();

	cout << buffer << "\n";

	return 0;
}

/*
10 5
abacdabcda
7 10 0
5 8 1
1 4 0
3 6 0
7 10 1
=====
cbcaaaabdd

10 1
agjucbvdfk
1 10 1
=====
abcdfgjkuv
*/
