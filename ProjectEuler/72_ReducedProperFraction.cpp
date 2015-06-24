// https://projecteuler.net/problem=72
// http://www.mathblog.dk/project-euler-72-reduced-proper-fractions/

#include <iostream>
#include <string.h>

using namespace std;

long long countReducedProperFraction(int n) {
	int* nums;
	int i, j;
	long long c;

	nums = new int[n + 1];

	for (i = 0; i <= n; i++) {
		nums[i] = i;
	}

	c = 0;
	for (i = 2; i <= n; i++) {
		if (nums[i] == i) {
			for (j = i; j <= n; j += i) {
				nums[j] = nums[j] / i * (i - 1);
			}
		}
		c += nums[i];
	}

	delete[] nums;

	return c;
}

int main(int argc, char* argv[]) {
	cout << countReducedProperFraction(8) << "\n";
	cout << countReducedProperFraction(1000000) << "\n";

	return 0;
}

/*
8
=====
21
*/
