// https://leetcode.com/problems/bulb-switcher/

#include <iostream>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int inc, sum, ans;

		sum = 1;
		inc = 1;
		ans = 0;

		while (n >= sum) {
			inc += 2;
			sum += inc;
			ans++;
		}

		return ans;
    }
};

int main(int argc, char* argv) {
	Solution s;

	cout << s.bulbSwitch(3) << "\n";

	return 0;
}

/*
3
=====
1
*/
