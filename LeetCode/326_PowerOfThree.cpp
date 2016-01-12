// https://leetcode.com/problems/power-of-three/

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
		double epsilon;
        int k, p;

		if (n == 0) return false;
        
		epsilon = 0.00000000000001;
        k = (int)(log((double)n) / log(3.0) + epsilon);
        p = (int)(pow(3.0, (double)k));
        
        return p == n;
    }
};

int main(int argc, char* argv) {
	Solution s;
	int i;

	for (i = 0; i < 100000; i++) {
		if (s.isPowerOfThree(i) != true) continue;
		cout << i << "\n";
	}

	return 0;
}
