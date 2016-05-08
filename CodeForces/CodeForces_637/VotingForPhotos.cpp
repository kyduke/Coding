// http://codeforces.com/contest/637/problem/A

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solve(vector<int> arr) {
	map<int, int> m;
	map<int, int>::iterator it;
	int hotest, i, k;
	vector<int> candidates;

	hotest = 0;
	for (i = 0; i < arr.size(); i++) {
		it = m.find(arr[i]);
		if (it == m.end()) {
			m.insert(make_pair(arr[i], 1));
			k = 1;
		} else {
			it->second++;
			k = it->second;
		}
		if (hotest < k) {
			hotest = k;
			candidates.clear();
			candidates.push_back(arr[i]);
		} else if (hotest == k) {
			candidates.push_back(arr[i]);
		}
	}

	return candidates[0];
}

int main(int argc, char* argv[]) {
	int n, i;
	vector<int> arr;

	cin >> n;
	arr.assign(n, 0);
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << solve(arr) << "\n";

	return 0;
}


/*
5
1 3 2 2 1
=====
2

9
100 200 300 200 100 300 300 100 200
=====
300
*/
