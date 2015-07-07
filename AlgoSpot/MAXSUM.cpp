// https://algospot.com/judge/problem/read/MAXSUM

#include <iostream>

using namespace std;

const int SIZE = 100000;

int maxSubArray(int *arr, int n) {
	int maxEndingHere, maxSoFar, i;

	maxEndingHere = maxSoFar = arr[0];
	for (i = 1; i < n; i++) {
		maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
		maxSoFar = max(maxSoFar, maxEndingHere);
	}

	return maxSoFar;
}

int main(int argc, char* argv[]) {
	int arr[SIZE];
	int T, N, i;

	cin >> T;
	while (T--) {
		cin >> N;
		i = 0;
		while (i < N) {
			cin >> arr[i++];
		}
		cout << maxSubArray(arr, N) << "\n";
	}

	return 0;
}

/*
2
4
1 2 3 4
3
-1 0 1
=====
10
1
*/
