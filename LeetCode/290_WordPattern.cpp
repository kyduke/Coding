// https://leetcode.com/problems/word-pattern/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        string patt;
		vector<string> strs;
		int i, j, s;

		if (str.size() > 0) {
			s = 0;
			for (i = 0; i < str.size(); i++) {
				if (str[i] == ' ') {
					strs.push_back(str.substr(s, i - s));
					s = i + 1;
				}
			}
			strs.push_back(str.substr(s, i - s));
		}

		patt = pattern;

		if (patt.size() != strs.size()) return false;

		for (i = 0; i < patt.size(); i++) {
			if (patt[i] == ' ') continue;
			for (j = i + 1; j < patt.size(); j++) {
				if (patt[j] == patt[i]) {
					if (strs[i].compare(strs[j]) != 0) return false;
					patt[j] = ' ';
				} else {
					if (strs[i].compare(strs[j]) == 0) return false;
				}
			}
		}

		return true;
    }
};

int main(int argc, char* argv[]) {
	Solution s;

	cout << s.wordPattern("abba", "dog cat cat dog") << "\n";
	cout << s.wordPattern("abba", "dog cat cat fish") << "\n";
	cout << s.wordPattern("aaaa", "dog cat cat dog") << "\n";
	cout << s.wordPattern("abba", "dog dog dog dog") << "\n";

	return 0;
}

/*
"abba", "dog cat cat dog"
=====
true

"abba", "dog cat cat fish"
=====
false

"aaaa", "dog cat cat dog"
=====
false

"abba", "dog dog dog dog"
=====
false
*/
