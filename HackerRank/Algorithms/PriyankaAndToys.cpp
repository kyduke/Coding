// https://www.hackerrank.com/challenges/priyanka-and-toys

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	vector<int> arr;
	int n, i, limit, answer;

	cin >> n;
	arr.assign(n, 0);
	i = 0;
	while (i < n) {
		cin >> arr[i];
		i++;
	}
	sort(arr.begin(), arr.end());

	answer = 0;
	limit = -1;
	for (i = 0; i < n; i++) {
		if (arr[i] > limit) {
			limit = arr[i] + 4;
			answer++;
		}
	}
	cout << answer << "\n";

	return 0;
}

/*
5
1 2 3 17 10
=====
3
*/
