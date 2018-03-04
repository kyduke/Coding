// https://leetcode.com/contest/weekly-contest-74/problems/number-of-matching-subsequences/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> digits[26];
        vector<vector<int>> arr;
        int ans, i, j, k, n, c, x;
        bool flag;
        
        ans = 0;
        
        for (i = 0; i < s.size(); i++) {
            k = s[i] - 'a';
			digits[k].push_back(i);
        }
        
        for (i = 0; i < words.size(); i++) {
            flag = true;
			c = -1;
            for (j = 0; j < words[i].size(); j++) {
				k = words[i][j] - 'a';
				flag = false;
				for (x = 0; x < digits[k].size(); x++) {
					if (digits[k][x] > c) {
						c = digits[k][x];
						flag = true;
						break;
					}
				}
				if (flag == false) break;
            }
            if (flag == true) ans++;
        }
        
        return ans;
    }
};

int main(int argc, char** argv) {
	Solution s;
	vector<string> vs;

	vs.push_back("a");
	vs.push_back("bb");
	vs.push_back("acd");
	vs.push_back("ace");

	cout << s.numMatchingSubseq("abcde", vs) << "\n";

	return 0;
}

/*
"abcde", ["a", "bb", "acd", "ace"]
=====
3
*/
