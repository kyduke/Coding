// https://leetcode.com/problems/reverse-vowels-of-a-string/

#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    string ret;
    int nextVowel(int idx, int direction) {
        char c;
    
        while (idx >= 0 && idx <= ret.size() - 1) {
            c = ret[idx];
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') break;
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') break;
            idx += direction;
        }
    
        return idx;
    }
public:
    string reverseVowels(string s) {
        char temp;
        int left, right;
        
        ret = s;
        left = nextVowel(0, 1);
        right = nextVowel(ret.size() - 1, -1);
        while (left < right) {
            temp = ret[left];
            ret[left] = ret[right];
            ret[right] = temp;
            
            left = nextVowel(left + 1, 1);
            right = nextVowel(right - 1, -1);
        }
        
        return ret;
    }
};

int main(int argc, char* argv[]) {
	Solution s;

	cout << s.reverseVowels("hello") << "\n";
	cout << s.reverseVowels("a.") << "\n";
	cout << s.reverseVowels("aA") << "\n";

	return 0;
}

/*
hello
=====
holle

a.
=====
a.

aA
=====
Aa
*/
