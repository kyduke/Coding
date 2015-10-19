// http://codeforces.com/problemset/problem/588/A

#include <iostream>

using namespace std;

const int SIZE = 100000;

int amounts[SIZE];
int prices[SIZE];
int n;

int solve() {
	int i, start, end, totalPrice, bigPrice, sumAmount;

	totalPrice = 0;

	end = n - 1;
	while (end >= 0) {
		start = end;
		bigPrice = prices[end];
		for (i = end - 1; i >= 0; i--) {
			if (bigPrice >= prices[i]) {
				bigPrice = prices[i];
				start = i;
			}
		}

		sumAmount = 0;
		for (i = start; i <= end; i++) {
			sumAmount += amounts[i];
		}

		totalPrice += sumAmount * prices[start];

		end = start - 1;
	}

	return totalPrice;
}

int main(int argc, char* argv[]) {
	int i;

	cin >> n;
	i = 0;
	while (i < n) {
		cin >> amounts[i] >> prices[i];
		i++;
	}

	cout << solve() << "\n";

	return 0;
}

/*
3
1 3
2 2
3 1
=====
10

3
1 3
2 1
3 2
=====
8
*/
