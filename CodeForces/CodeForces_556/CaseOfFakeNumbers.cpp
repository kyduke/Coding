// http://codeforces.com/problemset/problem/556/B

#include <iostream>

using namespace std;

bool possible(int n, int* nums) {
	int even, odd, i, k;

	even = (n -  nums[0]) % n;
	odd = n - even;

	for (i = 1; i < n; i++) {
		if (i % 2 == 0) {
			k = (nums[i] + even) % n;
		} else {
			k = (nums[i] + odd) % n;
		}

		if (i != k) return false;
	}

	return true;
}

int main(int argc, char* argv[]) {
	int nums[1000];
	int n, i;

	cin >> n;
	i = 0;
	while (i < n) {
		cin >> nums[i];
		i++;
	}

	if (possible(n, nums) == true) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	return 0;
}

/*
3
1 0 0
=====
Yes

5
4 2 1 4 3
=====
Yes

4
0 2 3 1
=====
No
*/
