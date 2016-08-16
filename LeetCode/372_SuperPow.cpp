// https://leetcode.com/problems/super-pow/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        vector<int> repeat;
		int i, r, c;

		if (b.size() < 0) return 1;
		if (b.size() == 1 && b[0] == 0) return 1;

		r = a % 1337;
		c = r;
		repeat.push_back(c);

		c = (c * r) % 1337;
		while (c != r) {
			repeat.push_back(c);
			c = (c * r) % 1337;
		}

		r = repeat.size();
		c = 0;
		for (i = 0; i < b.size(); i++) {
			c = (c * 10 + b[i]) % r;
		}

		c = (c + r - 1) % r;

		return repeat[c];
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> arr;

	arr.clear();
	arr.push_back(3);
	cout << s.superPow(2, arr) << "\n";

	arr.clear();
	arr.push_back(1);
	arr.push_back(0);
	cout << s.superPow(2, arr) << "\n";

	arr.clear();
	arr.push_back(0);
	cout << s.superPow(22179, arr) << "\n";

	arr.clear();
	arr.push_back(1);
	arr.push_back(0);
	cout << s.superPow(3, arr) << "\n";

	return 0;
}



/*
2
[3]
=====
8

2
[1,0]
=====
1024
*/
