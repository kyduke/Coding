// http://codeforces.com/contest/558/problem/B
// Amr and The Large Array

#include <iostream>
#include <map>

using namespace std;

const int LIMIT = 1000001;

multimap<int, int> reverseCounts;
int nums[LIMIT] = {0, };
int lefts[LIMIT] = {0, };
int rights[LIMIT] = {0, };

int maxNum;

void solve() {
	multimap<int, int>::reverse_iterator it;
	int i, maxCount, tempCount, maxLeft, tempLeft, maxRight, tempRight;

	for (i = 0; i <= maxNum; i++) {
		if (nums[i] == 0) continue;
		reverseCounts.insert(make_pair(nums[i], i));
	}

	maxCount = 0;
	it = reverseCounts.rbegin();
	while (it != reverseCounts.rend()) {
		tempCount = it->first;
		if (tempCount > maxCount) {
			maxCount = tempCount;
			maxLeft = lefts[it->second];
			maxRight = rights[it->second];
		} else if (tempCount == maxCount) {
			tempLeft = lefts[it->second];
			tempRight = rights[it->second];
			if ((maxRight - maxLeft) >= (tempRight - tempLeft)) {
				maxCount = tempCount;
				maxLeft = lefts[it->second];
				maxRight = rights[it->second];
			}
		}
		it++;
	}

	cout << maxLeft << " " << maxRight << "\n"; 
}

int main(int argc, char* argv[]) {
	int n, i, t;

	cin >> n;
	maxNum = 0;
	i = 0;
	while (i < n) {
		cin >> t;
		i++;
		nums[t]++;
		if (nums[t] == 1) {
			lefts[t] = i;
		}
		rights[t] = i;
		maxNum = max(maxNum, t);
	}

	solve();

	return 0;
}

/*
5
1 1 2 2 1
=====
1 5

5
1 2 2 3 1
=====
2 3

6
1 2 2 1 1 2
=====
1 5
*/
