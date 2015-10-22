#include <iostream>
#include <stdio.h>

using namespace std;

const int SIZE = 5000;
const int MAX_DISTANCE = 8030000;

int locations[SIZE];
int markStarts[SIZE];
int gaps[SIZE];
int N, K;

bool checkMoreKMarks(int distance) {
	int marks, i;

	marks = 0;

	for (i = 0; i < N; i++) {
		if (distance < locations[i] - markStarts[i]) continue;
		marks += (min(distance, locations[i]) - (locations[i] - markStarts[i])) / gaps[i] + 1;
	}
	
	return (marks >= K);
}

int solve() {
	int low, hi, mid;

	low = 0;
	hi = MAX_DISTANCE;

	while (low < hi) {
		mid = (hi - low) / 2 + low;
		if (checkMoreKMarks(mid) == true) {
			hi = mid;
		} else {
			if (low == mid) {
				low = hi;
			} else {
				low = mid;
			}
		}
	}

	return low;
}

int main(int argc, char* argv[]) {
	int T, i;

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		i = 0;
		while (i < N) {
			scanf("%d %d %d", &locations[i], &markStarts[i], &gaps[i]);
			i++;
		}
		printf("%d\n", solve());
	}

	return 0;
}
