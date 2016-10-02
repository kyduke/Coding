// https://projecteuler.net/problem=93

#include <iostream>
#include <set>

using namespace std;

set<int> results;

void getArithmeticExpression(double n, double* nums, int* visit) {
	int i;

	if (visit[0] == 1 && visit[1] == 1 && visit[2] == 1 && visit[3] == 1) {
		if (n > 0 && (int)n == n) {
			results.insert((int)n);
		}
		return;
	}

	for (i = 0; i < 4; i++) {
		if (visit[i] == 1) continue;
		{
			visit[i] = 1;
			getArithmeticExpression(n + nums[i], nums, visit);
			visit[i] = 0;
		}
		{
			visit[i] = 1;
			getArithmeticExpression(n - nums[i], nums, visit);
			visit[i] = 0;
		}
		{
			visit[i] = 1;
			getArithmeticExpression(n * nums[i], nums, visit);
			visit[i] = 0;
		}
		if (nums[i] != 0.0) {
			visit[i] = 1;
			getArithmeticExpression(n / nums[i], nums, visit);
			visit[i] = 0;
		}
	}
}

int getConsecutiveSize(double* nums) {
	int visit[4] = {0, };
	double pairs[4] = {0, };
	int i;

	results.clear();

	for (i = 0; i < 4; i++) {
		visit[i] = 1;
		getArithmeticExpression(nums[i], nums, visit);
		visit[i] = 0;
	}

	visit[2] = 1;
	visit[3] = 1;
	pairs[0] = nums[1] + nums[0];
	pairs[1] = nums[3] + nums[2];
	for (i = 0; i < 2; i++) {
		visit[i] = 1;
		getArithmeticExpression(pairs[i], pairs, visit);
		visit[i] = 0;
	}

	pairs[0] = nums[1] + nums[0];
	pairs[1] = nums[3] - nums[2];
	for (i = 0; i < 2; i++) {
		visit[i] = 1;
		getArithmeticExpression(pairs[i], pairs, visit);
		visit[i] = 0;
	}
	
	pairs[0] = nums[1] - nums[0];
	pairs[1] = nums[3] + nums[2];
	for (i = 0; i < 2; i++) {
		visit[i] = 1;
		getArithmeticExpression(pairs[i], pairs, visit);
		visit[i] = 0;
	}

	pairs[0] = nums[1] - nums[0];
	pairs[1] = nums[3] - nums[2];
	for (i = 0; i < 2; i++) {
		visit[i] = 1;
		getArithmeticExpression(pairs[i], pairs, visit);
		visit[i] = 0;
	}


	pairs[0] = nums[2] + nums[0];
	pairs[1] = nums[3] + nums[1];
	for (i = 0; i < 2; i++) {
		visit[i] = 1;
		getArithmeticExpression(pairs[i], pairs, visit);
		visit[i] = 0;
	}

	pairs[0] = nums[2] + nums[0];
	pairs[1] = nums[3] - nums[1];
	for (i = 0; i < 2; i++) {
		visit[i] = 1;
		getArithmeticExpression(pairs[i], pairs, visit);
		visit[i] = 0;
	}

	pairs[0] = nums[2] - nums[0];
	pairs[1] = nums[3] + nums[1];
	for (i = 0; i < 2; i++) {
		visit[i] = 1;
		getArithmeticExpression(pairs[i], pairs, visit);
		visit[i] = 0;
	}

	pairs[0] = nums[2] - nums[0];
	pairs[1] = nums[3] - nums[1];
	for (i = 0; i < 2; i++) {
		visit[i] = 1;
		getArithmeticExpression(pairs[i], pairs, visit);
		visit[i] = 0;
	}


	pairs[0] = nums[3] + nums[0];
	pairs[1] = nums[2] + nums[1];
	for (i = 0; i < 2; i++) {
		visit[i] = 1;
		getArithmeticExpression(pairs[i], pairs, visit);
		visit[i] = 0;
	}

	pairs[0] = nums[3] + nums[0];
	pairs[1] = nums[2] - nums[1];
	for (i = 0; i < 2; i++) {
		visit[i] = 1;
		getArithmeticExpression(pairs[i], pairs, visit);
		visit[i] = 0;
	}

	pairs[0] = nums[3] - nums[0];
	pairs[1] = nums[2] + nums[1];
	for (i = 0; i < 2; i++) {
		visit[i] = 1;
		getArithmeticExpression(pairs[i], pairs, visit);
		visit[i] = 0;
	}

	pairs[0] = nums[3] - nums[0];
	pairs[1] = nums[2] - nums[1];
	for (i = 0; i < 2; i++) {
		visit[i] = 1;
		getArithmeticExpression(pairs[i], pairs, visit);
		visit[i] = 0;
	}

	i = 0;
	for (set<int>::iterator it = results.begin(); it != results.end(); it++) {
		if (i + 1 != *it) break;
		i = *it;
	}

	return i;
}

int main(int argc, char* argv[]) {
	double nums[4];
	double maxNums[4];
	int i, j, k, l, r, max, limit;

	max = 0;
	limit = 10;
	for (i = 1; i < limit; i++) {
		nums[0] = (double)i;
		for (j = i + 1; j < limit; j++) {
			nums[1] = (double)j;
			for (k = j + 1; k < limit; k++) {
				nums[2] = (double)k;
				for (l = k + 1; l < limit; l++) {
					nums[3] = (double)l;
					cout << (int)nums[0] << (int)nums[1] << (int)nums[2] << (int)nums[3] << " ";
					r = getConsecutiveSize(nums);
					cout << r << "\n";

					if (r > max) {
						max = r;
						maxNums[0] = nums[0];
						maxNums[1] = nums[1];
						maxNums[2] = nums[2];
						maxNums[3] = nums[3];
					}
				}
			}
		}
	}

	cout << (int)maxNums[0] << (int)maxNums[1] << (int)maxNums[2] << (int)maxNums[3] << " ";
	cout << max << "\n";

	return 0;
}
