// https://leetcode.com/problems/perfect-squares/

#include <iostream>
#include <map>
#include <math.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int i, r, d, t, result;
        
        result = 0;
        if (n == 0) return result;

		for (r = sqrt((double)n); r > 0; r--) {
			i = r * r;
			if (result == 0) {
				result = n / i + numSquares(n % i);;
			} else {
				t = n / i;
				if (result < t + 1) break;
				t +=  + numSquares(n % i);
				result = min(result, t);
			}
		}

        return result;
    }
};

int main(int argc, char* argv[]) {
	Solution s;

	cout << s.numSquares(12) << "\n";
	cout << s.numSquares(13) << "\n";
	cout << s.numSquares(40) << "\n";
	cout << s.numSquares(43) << "\n";
	cout << s.numSquares(47) << "\n";
	cout << s.numSquares(48) << "\n";
	cout << s.numSquares(88) << "\n";
	cout << s.numSquares(9542) << "\n";

	return 0;
}
