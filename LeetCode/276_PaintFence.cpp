// LeetCode 276 Paint Fence

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
	int numWays(int n, int k) {
		return n * k == 0 ? 0 : k * pow((double)(k - 1), (double)(n - 1));
	}
};

int main(int argc, char* argv[]) {
	Solution s;

	cout << s.numWays(0, 0) << "\n";
	cout << s.numWays(1, 0) << "\n";
	cout << s.numWays(0, 1) << "\n";
	cout << s.numWays(1, 1) << "\n";
	cout << s.numWays(1, 3) << "\n";
	cout << s.numWays(3, 3) << "\n";

	return 0;
}
