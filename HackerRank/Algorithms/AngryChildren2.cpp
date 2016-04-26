// https://www.hackerrank.com/challenges/angry-children-2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define UINT64 unsigned long long

UINT64 solve(vector<UINT64> arr, int N, int K) {
	vector<UINT64> sums, triangles, diffs;
	UINT64 answer, sum, diff;
	int i;

	sort(arr.begin(), arr.end());

	sums.assign(N + 1, 0);
	triangles.assign(N + 1, 0);
	diffs.assign(N, 0);

	for (i = 1; i < N + 1; i++) {
		sums[i] = sums[i - 1] + arr[i - 1];
		triangles[i] = triangles[i - 1] + arr[i - 1] * i;
	}

	diff = 0;
	for (i = 0; i < K; i++) {
		diff += arr[i];
		diffs[0] += arr[i] * (K - i);
	}

	for (i = 1; i < N - K + 1; i++) {
		diff = diff + arr[i + K - 1] - arr[i - 1];
		diffs[i] = diffs[i - 1] + diff - arr[i - 1] * K;
	}

	answer = triangles[K] - diffs[0];

	for (i = 1; i < N - K + 1; i++) {
		sum = triangles[i + K] - triangles[i];
		sum -= (sums[i + K] - sums[i]) * i;
		sum -= diffs[i];
		if (answer > sum) answer = sum;
	}

	return answer;
}

int main(int argc, char* argv[]) {
	int N, K, i;
	vector<UINT64> arr;

	cin >> N;
	cin >> K;
	arr.assign(N, 0);
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cout << solve(arr, N, K);

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
40

10
4
1
2
3
4
10
20
30
40
100
200
=====
10
*/
