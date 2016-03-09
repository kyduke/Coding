// http://codeforces.com/contest/651/problem/B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& arr) {
	int ret, cnt, p, i;

	ret = 0;
	cnt = 0;

	sort(arr.begin(), arr.end());

	while (cnt < arr.size()) {
		p = 0;
		for (i = 0; i < arr.size(); i++) {
			if (arr[i] == 0) continue;
			if (p == 0) {
				p = arr[i];
				arr[i] = 0;
				cnt++;
			} else if (p < arr[i]) {
				p = arr[i];
				arr[i] = 0;
				cnt++;
				ret++;
			}
		}
	}

	return ret;
}

int main(int argc, char* argv[]) {
	vector<int> arr;
	int n, i;

	cin >> n;
	arr.assign(n, 0);
	i = 0;
	while (i < n) {
		cin >> arr[i];
		i++;
	}
	cout << solve(arr) << "\n";

	return 0;
}

/*
5
20 30 10 50 40
=====
4

4
200 100 100 200
=====
2
*/
