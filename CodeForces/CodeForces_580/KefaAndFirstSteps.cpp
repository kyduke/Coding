// http://codeforces.com/problemset/problem/580/A

#include <iostream>

using namespace std;

const int SIZE = 100001;

int nums[SIZE];
int n;

int maximumCountOfNonDecreasingSubsegment() {
	int count, i, currentCount;

	count = 1;
	currentCount = 1;
	for (i = 1; i < n; i++) {
		if (nums[i] < nums[i - 1]) {
			currentCount = 1;
		} else {
			currentCount++;
			count = max(count, currentCount);
		}
	}

	return count;
}

int main(int argc, char* argv[]) {
	int i;

	cin >> n;
	i = 0;
	while (i < n) {
		cin >> nums[i++];
	}

	cout << maximumCountOfNonDecreasingSubsegment() << "\n";

	return 0;
}

/*
6
2 2 1 3 4 1
=====
3

3
2 2 9
=====
3
*/
