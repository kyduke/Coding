// https://www.hackerrank.com/contests/hourrank-1/challenges/shafaet-and-array

#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 1000;

int nums[SIZE];
int n, k, l;

int solve() {
	int i, target, cost, minCost, upCount, downCount;

	sort(nums, nums + n);

	minCost = 2147483647;
	target = nums[n - 1];
	while (target) {
		upCount = 0;
		downCount = 0;
		for (i = 0; i < n; i++) {
			if (nums[i] >= target) {
				upCount += nums[i] - target;
			} else {
				downCount += target - nums[i];
			}
		}
		target--;

		if (upCount > downCount) break;
		cost = upCount * k + (downCount - upCount) * l;

		if (minCost > cost) {
			minCost = cost;
		} else {
			break;
		}
	}
	
	return minCost;
}

int main(int argc, char* argv[]) {
	int i;

	cin >> n >> k >> l;
	i = 0;
	while (i < n) {
		cin >> nums[i];
		i++;
	}

	cout << solve() << "\n";

	return 0;
}

/*
4 1 2
3 4 2 2
=====
3

3 2 1
5 5 5
=====
0
*/
