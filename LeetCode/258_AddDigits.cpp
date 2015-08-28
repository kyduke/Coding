// https://leetcode.com/problems/add-digits/

#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
		int n;

		while (true) {
			n = 0;
			while (num) {
				n += num % 10;
				num /= 10;
			}
			num = n;
			if (num < 10) break;
		}

		return num;
    }
};

int main(int argc, char* argv[]) {
	Solution s;

	cout << s.addDigits(38) << "\n";

	return 0;
}
