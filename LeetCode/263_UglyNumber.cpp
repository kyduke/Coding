// https://leetcode.com/problems/ugly-number/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
		if (num == 0) return false;

		while (true) {
			if (num % 2 != 0) break;
			num /= 2;
		}

		while (true) {
			if (num % 3 != 0) break;
			num /= 3;
		}

		while (true) {
			if (num % 5 != 0) break;
			num /= 5;
		}

		return (num == 1) ? true : false;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	int i;

	for (i = 1; i < 100; i++) {
		cout << i << ": " << s.isUgly(i) << "\n";
	}

	return 0;
}
