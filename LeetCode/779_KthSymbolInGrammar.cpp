// LeetCode Weekly Contest 70 A
// https://leetcode.com/contest/weekly-contest-70/problems/k-th-symbol-in-grammar/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
private:
	int solve(int n, int k) {
		int r;
		if (n == 1) {
			return 0;
		}
		r = solve(n - 1, k / 2);
		if (r == 0) {
			if (k % 2 == 0) {
				return 0;
			} else {
				return 1;
			}
		} else {
			if (k % 2 == 0) {
				return 1;
			} else {
				return 0;
			}
		}
		return 0;
	}
public:
    int kthGrammar(int n, int k) {
        return solve(n, k - 1);
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	
	cout << s.kthGrammar(3, 3) << "\n";
	cout << s.kthGrammar(1, 1) << "\n";
	cout << s.kthGrammar(2, 1) << "\n";
	cout << s.kthGrammar(2, 2) << "\n";
	cout << s.kthGrammar(4, 5) << "\n";
	cout << s.kthGrammar(3, 1) << "\n";

	return 0;
}
