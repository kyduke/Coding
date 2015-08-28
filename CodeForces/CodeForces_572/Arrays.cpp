// http://codeforces.com/problemset/problem/572/A

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int A, B, k, m;
	int maxA, minB;
	int i, t;

	cin >> A >> B >> k >> m;

	k--;
	i = 0;
	while (i < A) {
		cin >> t;
		if (i == k) maxA = t;
		i++;
	}

	m = B - m;
	i = 0;
	while (i < B) {
		cin >> t;
		if (i == m) minB = t;
		i++;
	}

	if (maxA < minB) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}

/*
3 3
2 1
1 2 3
3 4 5
=====
YES

3 3
3 3
1 2 3
3 4 5
=====
NO

5 2
3 1
1 1 1 1 1
2 2
=====
YES
*/
