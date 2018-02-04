// LeetCode Weekly Contest 70 C
// https://leetcode.com/contest/weekly-contest-70/problems/swap-adjacent-in-lr-string/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        int i, j, n;

		n = start.size();

		// L
		j = 0;
		for (i = 0; i < n; i++) {
			if (end[i] == 'L') {
				j = max(i, j);
				while (true) {
					if (j == n || start[j] == 'R') {
						return false;
					}
					if (start[j] == 'L') break;
					j++;
				}
				start[j] = 'X';
				start[i] = 'L';
			}
		}
		
		// R
		j = n - 1;
		for (i = n - 1; i >= 0; i--) {
			if (end[i] == 'R') {
				j = min(i, j);
				while (true) {
					if (j == -1 || start[j] == 'L') {
						return false;
					}
					if (start[j] == 'R') break;
					j--;
				}
				start[j] = 'X';
				start[i] = 'R';
			}
		}

		for (i = 0; i < n; i++) {
			if (start[i] != end[i]) return false;
		}

		return true;
    }
};

int main(int argc, char* argv[]) {
	Solution s;

	cout << s.canTransform("XLXRRXXRXX", "LXXXXXXRRR") << "\n"; // true
	cout << s.canTransform("RXXLRXRXL", "XRLXXRRLX") << "\n"; // true
	cout << s.canTransform("R", "R") << "\n"; //true
	cout << s.canTransform("RXXLRXRXL", "XRLXXRRXX") << "\n"; // false
	cout << s.canTransform("XXXXXLXXXX", "LXXXXXXXXX") << "\n"; // true

	return 0;
}
