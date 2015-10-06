// https://projecteuler.net/problem=124

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 100000;

int solve(int n) {
	int i, j;
	vector<pair<UINT64, int>> nums;

	for (i = 0; i < SIZE; i++) {
		nums.push_back(make_pair(1, i + 1));
	}

	for (i = 1; i < SIZE; i++) {
		if (nums[i].first == 1) {
			for (j = i; j < SIZE; j = j + nums[i].second) {
				nums[j].first *= (UINT64)nums[i].second;
			}
		}
	}

	sort(nums.begin(), nums.end());

	return nums[n - 1].second;
}

int main(int argc, char* argv[]) {
	cout << solve(10000) << "\n";

	return 0;
}
