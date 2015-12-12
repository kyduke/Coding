// http://careercup.com/question?id=5708890861731840

#include <iostream>
#include <vector>

using namespace std;

vector<int> nonDecreasingSequence(vector<int>& a, vector<int>& b) {
	vector<int> ret;
	int i, n, prev, small, big;

	n = a.size();
	ret.assign(n, 0);

	prev = -1;
	for (i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			small = b[i];
			big = a[i];
		} else {
			small = a[i];
			big = b[i];
		}

		if (small >= prev) {
			ret[i] = small;
		} else if (big >= prev) {
			ret[i] = big;
		} else {
			ret.clear();
			break;
		}
		prev = ret[i];
	}

	return ret;
}

int main(int argc, char* argv[]) {
	vector<int> a, b, c;
	int t, n, i;

	cin >> t;
	while (t--) {
		cin >> n;
		a.assign(n, 0);
		b.assign(n, 0);

		for (i = 0; i < n; i++) cin >> a[i];
		for (i = 0; i < n; i++) cin >> b[i];

		c = nonDecreasingSequence(a, b);
		if (c.size() == 0) {
			cout << "IMPOSSIBLE\n";
		} else {
			for (i = 0; i < n; i++) {
				cout << c[i] << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}

/*
3
3
1 2 3
4 4 4
3
3 2 1
6 5 4
2
1 0
10 2
=====
1 2 4
IMPOSSIBLE
1 2
*/
