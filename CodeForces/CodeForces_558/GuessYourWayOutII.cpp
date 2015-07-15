// http://codeforces.com/problemset/problem/558/D
// Guess Your Way Out! II
// Time limit exceeded on test 6

#include <iostream>
#include <set>

using namespace std;

unsigned long long startNumber[51];
set<unsigned long long> noNodes;
set<unsigned long long> yesNodes;
set<int> mustDepths;
set<unsigned long long> candidate;

void fillStartNumber() {
	int i;
	unsigned long long n;

	i = 0;
	n = 1;
	while (i <= 50) {
		startNumber[i] = n;
		i++;
		n *= 2;
	}
}

void solve(int h) {
	set<unsigned long long> result;
	set<int> visitDepths;
	set<unsigned long long>::iterator it;
	unsigned long long i, l, n;
	int d;
	bool check, yesCheck;

	if (yesNodes.size() > 0) {
		yesCheck = true;
	} else {
		yesCheck = false;
	}

	if (candidate.size() == 0) {
		i = startNumber[h - 1];
		l = startNumber[h];
		for (; i < l; i++) {
			candidate.insert(i);
		}
	}
	for (it = candidate.begin(); it != candidate.end(); it++) {
		check = !yesCheck;
		n = *it;
		d = h;
		visitDepths.clear();
		while (n) {
			if (yesNodes.find(n) != yesNodes.end()) {
				check = true;
				visitDepths.insert(d);
			}
			if (noNodes.find(n) != noNodes.end()) {
				check = false;
				break;
			}
			n /= 2;
			d--;
		}
		if (check && visitDepths.size() == mustDepths.size()) {
			result.insert(*it);
			if (result.size() > 1) {
				printf("Data not sufficient!\n");
				return;
			}
		}
	}

	if (result.size() == 0) {
		printf("Game cheated!\n");
	} else {
		printf("%I64d\n", *result.begin());
	}
}

int main(int argc, char* argv[]) {
	int h, q;
	int i, ans;
	unsigned long long k, L, R;

	fillStartNumber();

	scanf("%d %d", &h, &q);
	while (q--) {
		scanf("%d %I64d %I64d %d", &i, &L, &R, &ans);
		if (ans == 0) {
			for (k = L; k <= R; k++) {
				noNodes.insert(k);
			}
		} else {
			if (i < h) {
				mustDepths.insert(i);
				for (k = L; k <= R; k++) {
					yesNodes.insert(k);
				}
			} else {
				for (k = L; k <= R; k++) {
					candidate.insert(k);
				}
			}
		}
	}

	solve(h);

	return 0;
}

/*
3 1
3 4 6 0
=====
7

4 3
4 10 14 1
3 6 6 0
2 3 3 1
=====
14

4 2
3 4 6 1
4 12 15 1
=====
Data not sufficient!

4 2
3 4 5 1
2 3 3 1
=====
Game cheated!
*/
