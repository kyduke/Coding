// https://algospot.com/judge/problem/read/FENCE

#include <iostream>

using namespace std;

int fences[20000];

int getMaxArea(int start, int end) {
	int minHeight, minIndex, maxArea, i;

	if (start >= end) return 0;

	minHeight = 10001;
	minIndex = end;
	for (i = start; i < end; i++) {
		if (minHeight > fences[i]) {
			minHeight = fences[i];
			minIndex = i;
		}
	}

	maxArea = (end - start) * minHeight;
	if (minIndex < end) {
		maxArea = max(maxArea, getMaxArea(start, minIndex));
		maxArea = max(maxArea, getMaxArea(minIndex + 1, end));
	}

	return maxArea;
}

int main(int argc, char* argv[]) {
	int C, N, i;

	cin >> C;
	while (C--) {
		cin >> N;
		i = 0;
		while (i < N) {
			cin >> fences[i++];
		}

		cout << getMaxArea(0, N) << "\n";
	}

	return 0;
}

/*
3
7
7 1 5 9 6 7 3
7
1 4 4 4 4 1 1
4
1 8 2 2
=====
20
16
8
*/
