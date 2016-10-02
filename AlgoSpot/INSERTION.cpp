// https://algospot.com/judge/problem/read/INSERTION

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 50001;

int n;
int arr[SIZE];
int ans[SIZE];

void solve() {
	vector<int> remains;
	int i, k;

	remains.assign(n, 0);
	for (i = 0; i < n; i++) {
		remains[i] = i + 1;
	}

	for (i = n - 1; i >= 0; i--) {
		k = i - arr[i];
		ans[i] = remains[k];
		remains.erase(remains.begin() + k);
	}

	for (i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	int t, i;

	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> arr[i];
		}

		solve();
	}

	return 0;
}

/*
2
5
0 1 1 2 3
4
0 1 2 3
=====
5 1 4 3 2
4 3 2 1
*/
