// https://leetcode.com/problems/maximum-product-of-word-lengths/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
	int stringToMask(string& str) {
		int mask, i;

		mask = 0;
		for (i = 0; i < str.size(); i++) {
			mask |= 1 << (str[i] - 'a');
		}

		return mask;
	}
public:
    int maxProduct(vector<string>& words) {
		vector<pair<int, int>> LNMs;
        int i, j, maxP;

		for (i = 0; i < words.size(); i++) {
			LNMs.push_back(make_pair(words[i].size(), stringToMask(words[i])));
		}

		maxP = 0;

		for (i = 0; i < words.size(); i++) {
			for (j = i + 1; j < words.size(); j++) {
				if ((LNMs[i].second & LNMs[j].second) != 0) continue;
				maxP = max(maxP, LNMs[i].first * LNMs[j].first);
			}
		}

		return maxP;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<string> words;
	string data1[] = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
	string data2[] = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
	string data3[] = {"a", "aa", "aaa", "aaaa"};

	words.clear();
	words.assign(data1, data1 + 6);
	cout << s.maxProduct(words) << "\n";

	words.clear();
	words.assign(data2, data2 + 7);
	cout << s.maxProduct(words) << "\n";

	words.clear();
	words.assign(data3, data3 + 4);
	cout << s.maxProduct(words) << "\n";

	return 0;
}

/*
["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
=====
16

["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
=====
4

["a", "aa", "aaa", "aaaa"]
=====
0
*/
