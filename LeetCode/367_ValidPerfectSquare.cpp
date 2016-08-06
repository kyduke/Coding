// https://leetcode.com/problems/valid-perfect-square/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int a, b;
        
        a = num;
        b = 1;
        while (a > b) {
            b *= 2;
            a = num / b;
        }
        
        a = b / 2;
        while (a <= b) {
            if (a * a == num) {
                return true;
            } else if (a * a > num) {
                break;
            }
            a++;
        }
        
        return false;
    }
};

int main(int argc, char* argv[]) {
	Solution s;

	cout << s.isPerfectSquare(9) << "\n";
	cout << s.isPerfectSquare(36) << "\n";
	cout << s.isPerfectSquare(1) << "\n";

	return 0;
}
