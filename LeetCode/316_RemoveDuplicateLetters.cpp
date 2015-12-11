// https://leetcode.com/problems/remove-duplicate-letters/
// failed

#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
		vector<int> bits;
		set<char> ss;
		set<char>::iterator it;
		string ret;
        int i, j, b, all, start;
		bool found;
        
		bits.assign(s.size(), 0);

		all = 0;
        for (i = s.size() - 1; i >= 0; i--) {
			j = s[i] - 'a';
			b = 1 << j;
			all |= b;
			bits[i] = all;
			ss.insert(s[i]);
        }

		ret = "";

		start = -1;
		while (ss.size()) {
			found = false;
			for (it = ss.begin(); it != ss.end(); it++) {
				j = *it - 'a';
				b = 1 << j;
				for (i = start + 1; i < bits.size(); i++) {
					if (*it != s[i]) continue;
					if ((bits[i] & all) == all) {
						start = i;
						ret += s[i];
						all ^= b;
						ss.erase(it);
						found = true;
						break;
					}
				}
				if (found) break;
			}
		}

        return ret;
    }
};

int main(int argc, char* argv[]) {
	Solution s;

	cout << s.removeDuplicateLetters("bcabc") << "\n";
	cout << s.removeDuplicateLetters("bddbccd") << "\n";
	cout << s.removeDuplicateLetters("cbacdcbc") << "\n";
	cout << s.removeDuplicateLetters("mitnlruhznjfyzmtmfnstsxwktxlboxutbic") << "\n";

	return 0;
}

/*
bcabc
=====
abc

cbacdcbc
=====
acdb
*/
