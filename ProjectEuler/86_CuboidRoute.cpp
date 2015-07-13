// https://projecteuler.net/problem=86
// http://www.mathblog.dk/project-euler-86-shortest-path-cuboid/

#include <iostream>
#include <math.h>

using namespace std;

int solve(int n) {
	int count, i, j;
	double s;

	count = 0;
	i = 2;
	while (count < n) {
		i++;
		for (j = 3; j <= 2 * i; j++) {
			s = sqrt((double)(i * i + j * j));
			if (s == (int)s) {
				if (i >= j) {
					count += j / 2;
				} else {
					count += 1 + i - ((j + 1) / 2);
				}
			}
		}
	}

	return i;
}

int main(int argc, char* argv[]) {

	cout << solve(1000000) << "\n";

	return 0;
}
