// https://leetcode.com/problems/sum-of-two-integers/

#include <iostream>

using namespace std;

class SolutionOnlyPositive {
public:
    int getSum(int a, int b) {
        int c, bit, prev;
        
        c = 0;
        bit = 1;
        prev = 0;
        while (a >= bit || b >= bit) {
            if ((a & bit) && (b & bit)) {
                if (prev == 1) {
                    c |= bit;
                } else {
                    prev = 1;
                }
            } else if ((a & bit) || (b & bit)) {
                if (prev == 0) {
                    c |= bit;
                }
            } else {
                if (prev == 1) {
                    c |= bit;
                    prev = 0;
                }
            }
            bit = bit << 1;
        }

		if (prev == 1) c |= bit;
        
        return c;
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        int c;
        
        while(b != 0){
            c = a & b;
            a = a ^ b;
            b = c << 1;
        }
        
        return a;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	int a, b;

	a = 1;
	b = 2;
	cout << a << " + " << b << " = " << s.getSum(a, b) << "\n";

	a = 2;
	b = 3;
	cout << a << " + " << b << " = " << s.getSum(a, b) << "\n";

	return 0;
}
