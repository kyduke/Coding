// http://community.topcoder.com/stat?c=problem_statement&pm=13960&rd=16514

#include <iostream>

using namespace std;

class LuckyXor {
public:
	int construct(int);
};

int LuckyXor::construct(int a) {
	int i, n, d;
	bool passed;

	for (i = a + 1; i <= 100; i++) {
		n = a ^ i;
		passed = false;
		while (n) {
			d = n % 10;
			if (d != 4 && d != 7) {
				passed = false;
				break;
			} else {
				passed = true;
			}
			n /= 10;
		}
		if (passed == true) return i;
	}

	return -1;
}

int main(int argc, char* argv[]) {
	LuckyXor luckyXor;

	cout << luckyXor.construct(4) << "\n";
	cout << luckyXor.construct(19) << "\n";
	cout << luckyXor.construct(88) << "\n";
	cout << luckyXor.construct(36) << "\n";

	return 0;
}

/*
4
=====
40
    	
19
=====
20

88
=====
92
    	
36
=====
-1
*/
