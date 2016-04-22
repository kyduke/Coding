// Google Code Jam Round 1A 2016 Problem C. BFFs

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solve(vector<int> BFFs) {
	vector<int> DBFFs;
	set<int> used;
	int circle, i, current, next, end, sum;

	DBFFs.assign(BFFs.size(), 0);

	circle = 0;
	for (i = 0; i < BFFs.size(); i++) {
		used.clear();
		current = i;
		next = BFFs[current];
		end = i;
		while (used.find(next) == used.end()) {
			used.insert(current);
			end = current;
			current = next;
			next = BFFs[next];
		}

		if (next == end) {
			DBFFs[end] = max(DBFFs[end], (int)used.size());
		} else if (next == i) {
			circle = max(circle, (int)used.size() + 1);
		}
	}

	sum = 0;
	for (i = 0; i < DBFFs.size(); i++) {
		sum += DBFFs[i];
	}

	return max(circle, sum);
}

int main(int argc, char* argv[]) {
	int T, t, n, i;
	vector<int> BFFs;

	cin >> T;
	t = 0;
	while (t < T) {
		cin >> n;
		BFFs.assign(n, 0);
		for (i = 0; i < n; i++) {
			cin >> BFFs[i];
			BFFs[i]--;
		}
		cout << "Case #" << ++t << ": " << solve(BFFs) << "\n";
	}

	return 0;
}

/*
4
4
2 3 4 1
4
3 3 4 1
4
3 3 4 3
10
7 8 10 10 9 2 9 6 3 3
=====
Case #1: 4
Case #2: 3
Case #3: 3
Case #4: 6
*/
