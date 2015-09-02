// https://projecteuler.net/problem=109

#include <iostream>

using namespace std;

int getCheckoutChances(int n) {
	int points[63] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 25, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 60, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 50, 0};
	int count;
	int q[4], p[3], step, i;

	count = 0;
	step = 0;
	q[0] = 41;
	p[0] = 0;
	while (true) {
		if (step == 3) {
			if (p[0] + p[1] + p[2] == n) count++;
			step--;
			q[step]++;
		}
		i = q[step];
		if (i < 63) {
			p[step] = points[i];
			step++;
			if (step == 1) {
				q[step] = 0;
			} else {
				q[step] = i;
			}
		} else {
			step--;
			q[step]++;
			if (step == 0 && q[step] == 62) break;
		}
	}

	return count;
}

int main(int argc, char* argv[]) {
	int i, sum;

	sum = 0;
	for (i = 2; i < 100; i++) {
		sum += getCheckoutChances(i);
	}

	cout << sum << "\n";

	return 0;
}
