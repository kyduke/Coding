//	https://projecteuler.net/problem=85

#include <iostream>

using namespace std;

const int GOAL = 2000000;

int countOfRectangles(int w, int h) {
	int x, y, w2, h2, count;

	count = 0;
	for (x = 0; x < h; x++) {
		h2 = h - x;
		for (y = 0; y < w; y++) {
			w2 = w - y;
			count += h2 * w2;
		}
	}

	return count;
}

int main(int argc, char* argv[]) {
	int i, j, limit, current, prev;
	int minCount, answer;

	minCount = GOAL;
	limit = GOAL;
	for (i = 1; i < limit; i++) {
		prev = GOAL;
		for (j = i; j < limit; j++) {
			current = countOfRectangles(i, j);
			if (current > GOAL) {
				current -= GOAL;
			} else {
				current = GOAL - current;
			}
			if (current > prev) {
				if (prev < minCount) {
					minCount = prev;
					answer = i * (j - 1);
				}
				limit = j;
				break;
			}
			prev = current;
		}
	}

	cout << answer << "\n";
	
	return 0;
}
