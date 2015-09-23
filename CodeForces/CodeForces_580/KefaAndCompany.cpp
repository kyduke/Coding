// http://codeforces.com/contest/580/problem/B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long UINT64;

vector<pair<int, int>> companies;
int d;

UINT64 getMaximumFriendship() {
	UINT64 sum, currentSum;
	int i, limit, startIndex;

	sort(companies.begin(), companies.end());

	sum = 0;
	currentSum = 0;
	startIndex = 0;
	for (i = 0; i < companies.size(); i++) {
		limit = companies[i].first - d;
		while (companies[startIndex].first <= limit) {
			currentSum -= companies[startIndex].second;
			startIndex++;
		}
		currentSum += companies[i].second;
		sum = max(sum, currentSum);
	}

	return sum;
}

int main(int argc, char* argv[]) {
	int n, m, s;

	cin >> n >> d;
	while (n--) {
		cin >> m >> s;
		companies.push_back(make_pair(m, s));
	}

	cout << getMaximumFriendship() << "\n";

	return 0;
}

/*
4 5
75 5
0 100
150 20
75 1
=====
100

5 100
0 7
11 32
99 10
46 8
87 54
=====
111
*/
