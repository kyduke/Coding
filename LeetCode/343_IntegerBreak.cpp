// https://leetcode.com/problems/integer-break/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
		int answer, i, a, r;

		i = (n + 1) / 3;
		if (i < 2) i = 2;
		r = n % i;
		a = n / i;
		answer = 1;
		while (r--) {
			answer *= a + 1;
			i--;
		}
		while (i--) {
			answer *= a;
		}

		return answer;
    }
};

int main(int argc, char* argv[]) {
	Solution s;

	cout << "2: " << s.integerBreak(2) << "\n";
	cout << "10: " << s.integerBreak(10) << "\n";
	cout << "55: " << s.integerBreak(55) << "\n";

	return 0;
}

/*
2
=====
1

10
=====
36
*/
