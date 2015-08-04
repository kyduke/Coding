#include <iostream>

using namespace std;

const int LIMIT = 1000001;
const int HALF = LIMIT / 2;

int sumOfTheProperDivisors[LIMIT] = {0, };
int visits[LIMIT] = {0, };
int counts[LIMIT] = {0, };

void fillSum() {
	int i, j;

	for (i = 0; i < LIMIT; i++) sumOfTheProperDivisors[i] = 1;

	for (i = 2; i <= HALF; i++) {
		for (j = i * 2; j < LIMIT; j += i) {
			sumOfTheProperDivisors[j] += i;
		}
	}

	for (i = 0; i < LIMIT; i++) {
		if (sumOfTheProperDivisors[i] >= LIMIT - 1) {
			sumOfTheProperDivisors[i] = i;
		}
	}
}

void findAmicableChain() {
	int i;
	int start, next, count;
	int maxCount;

	maxCount = 0;
	for (i = 1; i < LIMIT; i++) {
		if (sumOfTheProperDivisors[i] != i) {
			start = i;
			visits[start] = start;
			counts[start] = 0;
			count = 1;
			next = sumOfTheProperDivisors[i];
			while (1) {
				if (next == sumOfTheProperDivisors[next]) {
					break;
				}

				if (visits[next] == start) {
					count -= counts[next];
					if (maxCount < count) {
						maxCount = count;
						cout << count << ": " << next << "\n";
					}
					break;
				}

				visits[next] = start;
				counts[next] = count;
				count++;
				next = sumOfTheProperDivisors[next];
			}
		}
	}
}

int main(int argc, char* argv[]) {
	fillSum();

	findAmicableChain();

	return 0;
}
