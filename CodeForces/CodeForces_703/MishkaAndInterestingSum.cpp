// http://codeforces.com/contest/703/problem/D
// Timeout

#include <iostream>
#include <map>

using namespace std;

const int SIZE = 1000000;

int arr[SIZE] = {0, };

int solve(int l, int r) {
	map<int, int> m;
	map<int, int>::iterator it;
	int i, a;

	for (i = l - 1; i < r; i++) {
		a = arr[i];
		it = m.find(a);
		if (it == m.end()) {
			m.insert(make_pair(a, 1));
		} else {
			it->second++;
		}
	}

	a = 0;
	for (it = m.begin(); it != m.end(); it++) {
		if (it->second % 2 == 0) {
			a ^= it->first;
		}
	}

	return a;
}

int main(int argc, char* argv[]) {
	int n, i, m, l, r;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cin >> m;
	while (m--) {
		cin >> l >> r;
		cout << solve(l, r) << "\n";
	}

	return 0;
}

/*
3
3 7 8
1
1 3
=====
0

7
1 2 1 3 3 2 3
5
4 7
4 5
1 3
1 7
1 5
=====
0
3
1
3
2
*/
