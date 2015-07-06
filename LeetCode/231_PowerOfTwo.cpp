// https://leetcode.com/problems/power-of-two/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
		if (n == 0) return false;
		while (n > 1) {
			if (n % 2 == 1) {
				return false;
			}
			n = n / 2;
		}
        return true;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	int i;

	for (i = 0; i < 10000000; i++) {
		if (s.isPowerOfTwo(i) == true) {
			cout << i << " ";
		}
	}
	cout << "\n";

	return 0;
}
