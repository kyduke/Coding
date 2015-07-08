// https://leetcode.com/problems/number-of-digit-one/

#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int depth, length, current, under;
		int result;

		result = 0;

		depth = 1;
		length = 0;
		while (n / depth) {
			under = n % depth;
			current = (n % (depth * 10)) / depth;
			if (current == 1) {
				result += under + 1;
			} else if (current > 1) {
				result += depth;
			}
			result += current * length * (depth / 10);
			depth *= 10;
			length++;
		}

		return result;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	int i;

	for (i = 0; i <= 100; i++) {
		cout << i << ": " << s.countDigitOne(i) << "\n";
	}

	for (i = 9; i < 1000; i = i * 10 + 9) {
		cout << i << ": " << s.countDigitOne(i) << "\n";
	}
	cout << 1000 << ": " << s.countDigitOne(1000) << "\n";

	return 0;
}
