// http://careercup.com/question?id=5708890861731840

#include <iostream>
#include <vector>

using namespace std;

bool nonDecreasingSequence(vector<int>& a, vector<int>& b, vector<int>&c, int idx, int bit) {
	if (idx == a.size()) {
		return bit == 3;
	}

	if (idx == 0 || a[idx] >= c[idx - 1]) {
		c[idx] = a[idx];
		if (nonDecreasingSequence(a, b, c, idx + 1, bit | 1) == true) return true;
	}

	if (idx == 0 || b[idx] >= c[idx - 1]) {
		c[idx] = b[idx];
		if (nonDecreasingSequence(a, b, c, idx + 1, bit | 2) == true) return true;
	}

	return false;
}

int main(int argc, char* argv[]) {
	vector<int> a, b, c;
	int t, n, i;

	cin >> t;
	while (t--) {
		cin >> n;
		a.assign(n, 0);
		b.assign(n, 0);
		c.assign(n, 0);

		for (i = 0; i < n; i++) cin >> a[i];
		for (i = 0; i < n; i++) cin >> b[i];

		if (nonDecreasingSequence(a, b, c, 0, 0) == true) {
			for (i = 0; i < n; i++) {
				cout << c[i] << " ";
			}
			cout << "\n";
		} else {
			cout << "IMPOSSIBLE\n";
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
