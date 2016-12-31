// LeetCode 276 Paint Fence

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
	int numWays(int n, int k) {
		int i, t;
		int c[2] = {0, 1};

		if (n == 0 || k == 0) return 0;
		if (n == 1) return k;

		for (i = 1; i < n - 1; i++) {
			t = (c[0] + c[1]) * (k - 1);
			c[0] = c[1];
			c[1] = t;
		}
		
		return k * (c[0] * (k - 1) + c[1] * k);
	}
	int numWaysSimple(int n, int k) {
		return n * k == 0 ? 0 : k * pow((double)(k - 1), (double)(n - 1));
	}
};

int main(int argc, char* argv[]) {
	Solution s;

	cout << s.numWays(0, 0) << ": 0 0\n";
	cout << s.numWays(1, 0) << ": 1 0\n";
	cout << s.numWays(0, 1) << ": 0 1\n";
	cout << s.numWays(1, 1) << ": 1 1\n";
	cout << s.numWays(2, 1) << ": 2 1\n";
	cout << s.numWays(100, 1) << ": 100 1\n";
	cout << s.numWays(1, 3) << ": 1 3\n";
	cout << s.numWays(2, 3) << ": 2 3\n";
	cout << s.numWays(3, 3) << ": 3 3\n";
	cout << s.numWays(4, 3) << ": 4 3\n";

	return 0;
}
