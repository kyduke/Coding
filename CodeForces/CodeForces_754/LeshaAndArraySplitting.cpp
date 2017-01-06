// http://codeforces.com/problemset/problem/754/A

#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int>& arr, int n) {
	vector<int> ans;
	int i, j, sum;

	sum = 0;
	for (i = 0; i < n; i++) {
		sum += arr[i];
		if (sum != 0 && (i + 1 == n || arr[i + 1] != 0)) {
			ans.push_back(i);
			sum = 0;
		}
	}

	if (ans.size() == 0) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	cout << ans.size() << "\n";
	i = 0;
	for (j = 0; j < ans.size(); j++) {
		cout << i + 1 << " " << ans[j] + 1 << "\n";
		i = ans[j] + 1;
	}
};

int main(int argc, char* argv[]) {
	vector<int> arr;
	int n, i;

	cin >> n;
	arr.assign(n, 0);

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	solve(arr, n);

	return 0;
}

/*
3
1 2 -3
=====
YES
2
1 2
3 3

8
9 -12 3 4 -4 -10 7 3
=====
YES
2
1 2
3 8

1
0
=====
NO

4
1 2 3 -5
=====
YES
4
1 1
2 2
3 3
4 4
*/
