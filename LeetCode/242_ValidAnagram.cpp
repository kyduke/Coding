// https://leetcode.com/problems/valid-anagram/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
		int alphabets[26] = {0, };
		int i;

		if (s.size() != t.size()) return false;

		for (i = 0; i < s.size(); i++) {
			alphabets[ s[i] - 'a' ]++;
			alphabets[ t[i] - 'a' ]--;
		}

		for (i = 0; i < 26; i++) {
			if (alphabets[i] != 0) return false;
		}

		return true;
    }
};

int main(int argc, char* argv[]) {
	Solution s;

	cout << s.isAnagram("anagram", "nagaram") << "\n";
	cout << s.isAnagram("rat", "cat") << "\n";

	return 0;
}
