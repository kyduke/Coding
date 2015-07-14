// http://codeforces.com/contest/558/problem/C
// Amr and Chemistry

#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int LIMIT = 10000000;

multiset<int> nums;
int counts[LIMIT] = {0, };
int moves[LIMIT] = {0, };
int limit;

void fillCountAndMove(int a) {
	int i, j, move;
	set<int> visit;

	move = 0;
	while (a) {
		j = move++;
		for (i = a; i < limit; i *= 2) {
			if (visit.find(i) != visit.end()) break;
			visit.insert(i);
			counts[i]++;
			moves[i] += j++;
		}
		a /= 2;
	}
}

int getMinimumOperations(int n) {
	int i, result;
	multiset<int>::iterator it;

	limit = *(nums.rbegin()) + 1;

	for (it = nums.begin(); it != nums.end(); it++) {
		fillCountAndMove(*it);
	}

	result = LIMIT;
	for (i = 0; i < limit; i++) {
		if (counts[i] == n) {
			result = min(result, moves[i]);
		}
	}

	return result;
}

int main(int argc, char* argv[]) {
	int n, i, a;

	cin >> n;
	i = 0;
	while (i < n) {
		cin >> a;
		nums.insert(a);
		i++;
	}

	cout << getMinimumOperations(n) << "\n";

	return 0;
}

/*
3
4 8 2
=====
2

3
3 5 6
=====
5
*/
