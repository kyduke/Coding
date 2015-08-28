// https://leetcode.com/problems/ugly-number-ii/

#include <iostream>
#include <set>

using namespace std;

class Solution {
private:
	set<int> uglyNumbers;
public:
    int nthUglyNumber(int num) {
		set<int>::iterator it;
		unsigned long long n;

		if (num == 0) return 0;

		if (uglyNumbers.size() == 0) {
			uglyNumbers.insert(1);
			
			it = uglyNumbers.begin();
			while (it != uglyNumbers.end()) {
				n = *it * 2;
				if (n > 2147483647) break;
				uglyNumbers.insert(n);
				it++;
			}
			cout << uglyNumbers.size() << "\n";

			it = uglyNumbers.begin();
			while (it != uglyNumbers.end()) {
				n = *it * 3;
				if (n > 2147483647) break;
				uglyNumbers.insert(n);
				it++;
			}
			cout << uglyNumbers.size() << "\n";

			it = uglyNumbers.begin();
			while (it != uglyNumbers.end()) {
				n = *it * 5;
				if (n > 2147483646) break;
				uglyNumbers.insert(n);
				it++;
			}
			cout << uglyNumbers.size() << "\n";
		}

		it = next(uglyNumbers.begin(), num - 1);

		return *it;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	int i;

	for (i = 1; i < 100; i++) {
		cout << i << ": " << s.nthUglyNumber(i) << "\n";
	}

	return 0;
}
