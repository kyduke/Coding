// https://www.hackerrank.com/challenges/angry-children

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	vector<int> arr;
	int n, k, i, answer;

	cin >> n;
	cin >> k;

	arr.assign(n, 0);
	i = 0;
	while (i < n) {
		cin >> arr[i];
		i++;
	}
	sort(arr.begin(), arr.end());

	k--;
	answer = 1000000000;
	for (i = 0; i < n - k; i++) {
		if (answer > arr[i + k] - arr[i]) answer = arr[i + k] - arr[i];
	}

	cout << answer << "\n";

	return 0;
}

/*
7
3
10
100
300
200
1000
20
30
=====
20
*/
