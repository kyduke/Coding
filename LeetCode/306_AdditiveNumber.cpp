// https://leetcode.com/problems/additive-number/

#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    string str;
    int getNextNumber(int i, int size) {
        int n;
        
        n = 0;
        if (i < str.size() && str[i] == '0') return n;
        
        while (size--) {
            if (i >= str.size()) break;
            n = n * 10 + (str[i] - '0');
            i++;
        }
        
        return n;
    }
    bool solve(int i, int sa, int sb) {
        int sizeA, sizeB, sizeC, a, b, c, d, pa, pb, pc;
        
        if (i >= str.size()) return true;
        
        pa = -1;
        for (sizeA = sa; sizeA < str.size(); sizeA++) {
            a = getNextNumber(i, sizeA);
			//cout << i << " a: " << a << "\n";
            if (pa == a) break;
            pa = a;
            pb = -1;
            for (sizeB = sb; sizeB < str.size(); sizeB++) {
                b = getNextNumber(i + sizeA, sizeB);
				//cout << i << " b: " << b << "\n";
                if (pb == b) break;
                pb = b;
                d = a + b;
                pc = -1;
                for (sizeC = 1; sizeC < str.size(); sizeC++) {
                    c = getNextNumber(i + sizeA + sizeB, sizeC);
					//cout << i << " c: " << c << "\n";
                    if (pc == c) break;
                    pc = c;
                    if (c == d) {
						if (i + sizeA + sizeB + sizeC == str.size()) return true;
                        if (solve(i + sizeA, sizeB, sizeC) == true) {
                            return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
public:
    bool isAdditiveNumber(string num) {
        int i, sizeA, sizeB, sizeC, a, b, c, d, pa, pb, pc;
        
        if (num.size() < 3) return false;
        
        str = num;
        
        return solve(0, 1, 1);
    }
};

int main(int argc, char* argv[]) {
	Solution s;

	cout << s.isAdditiveNumber("112233") << "\n";
	cout << s.isAdditiveNumber("112358") << "\n";
	cout << s.isAdditiveNumber("199100199") << "\n";
	cout << s.isAdditiveNumber("1203") << "\n";

	return 0;
}
