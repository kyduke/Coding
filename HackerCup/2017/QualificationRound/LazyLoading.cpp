// Facebook HackerCup 2017 B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& arr) {
	int ans, start, end, count;

	sort(arr.begin(), arr.end());

	ans = 0;
	end = arr.size() - 1;
	for (start = 0; start <= end; start++) {
		count = 1;
		while (count < arr[start] && start < end) {
			count++;
			end--;
		}
		if (count == arr[start]) ans++;
	}

	return ans;
}

int main(int argc, char* argv[]) {
	vector<int> arr;
	int t, ti, n, i, a;

	cin >> t;
	for (ti = 1; ti <= t; ti++) {
		cin >> n;
		arr.assign(n, 0);
		for (i = 0; i < n; i++) {
			cin >> a;
			arr[i] = 50 / a;
			if (50 % a) arr[i]++;
		}

		cout << "Case #" << ti << ": " << solve(arr);
		if (ti < t) cout << "\n";
	}

	return 0;
}

/*
5
4
30
30
1
1
3
20
20
20
11
1
2
3
4
5
6
7
8
9
10
11
6
9
19
29
39
49
59
10
32
56
76
8
44
60
47
85
71
91
=====
Case #1: 2
Case #2: 1
Case #3: 2
Case #4: 3
Case #5: 8
*/
