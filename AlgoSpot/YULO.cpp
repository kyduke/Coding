// https://algospot.com/judge/problem/read/YULO

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	vector<int> arr;
	int T, N, i, j, maxSum;

	cin >> T;
	while (T--) {
		cin >> N;
		arr.clear();
		arr.assign(N, 0);
		i = 0;
		while (i < N) {
			cin >> arr[i];
			i++;
		}
		sort(arr.begin(), arr.end());
		maxSum = 0;
		i = 0;
		j = N - 1;
		while (i < j) {
			if (maxSum < arr[i] + arr[j]) maxSum = arr[i] + arr[j];
			i++;
			j--;
		}
		if (i == j) {
			if (maxSum < arr[i] + arr[j]) maxSum = arr[i] + arr[j];
		}
		printf("%.1f\n", (double)maxSum / 2.0);
	}

	return 0;
}

/*
3
3
48 96 73
4
0 0 98 99
5
35 85 94 76 40
=====
73.0
49.5
76.0
*/
