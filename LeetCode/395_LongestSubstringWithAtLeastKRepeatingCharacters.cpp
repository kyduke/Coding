// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> counts[26];
        int n, i, j, a;
        char c;
        bool flag;
        
        n = s.size();
        for (i = 0; i < 26; i++) {
            counts[i].assign(n + 1, 0);
        }
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < 26; j++) {
                counts[j][i + 1] = counts[j][i];
            }
            c = s[i] - 'a';
            counts[c][i + 1]++;
        }
        
        while (n >= k) {
            for (i = 0; i <= s.size() - n; i++) {
				flag = true;
                for (j = 0; j < 26; j++) {
                    a = counts[j][i + n] - counts[j][i];
                    if (a != 0 && a < k) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return n;
                }
            }
            n--;
        }
        
        return 0;
    }
};

int main(int argc, char* argv[]) {
	Solution s;

	cout << s.longestSubstring("aaabb", 3) << "\n";
	cout << s.longestSubstring("ababbc", 2) << "\n";
	cout << s.longestSubstring("abbbc", 3) << "\n";

	return 0;
}

/*
aaabb 3
=====
3

ababbc 2
=====
5

abbbc 3
=====
3
*/
