// https://leetcode.com/problems/coin-change/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		vector<int> cache;
		int i, j, k, maxInt, ans;

		if (amount == 0) return 0;
		if (coins.size() == 0) return -1;

		sort(coins.begin(), coins.end());

		maxInt = 2000000000;
		cache.assign(amount + 1, maxInt);

		cache[0] = 0;
		for (i = 0; i <= amount; i++) {
			for (j = 0; j < coins.size(); j++) {
				k = i + coins[j];
				if (k > amount) continue;
				if (cache[k] > cache[i] + 1) cache[k] = cache[i] + 1;
			}
		}

		return cache[amount] == maxInt ? -1 : cache[amount];
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> arr;
	int data0[] = {1, 2, 5};
	int data1[] = {2};
	int data2[] = {186, 419, 83, 408};

	arr.assign(data0, data0 + 3);
	cout << s.coinChange(arr, 11) << "\n";

	arr.assign(data1, data1 + 1);
	cout << s.coinChange(arr, 3) << "\n";

	arr.assign(data2, data2 + 4);
	cout << s.coinChange(arr, 6249) << "\n";

	return 0;
}


/*
[1, 2, 5], 11
=====
3

[2], 3
=====
-1
*/
