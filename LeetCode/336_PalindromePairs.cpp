// https://leetcode.com/problems/palindrome-pairs/
// Brute-Force, Time Limit Exceeded

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
	bool isPalindrome(string& a, string& b) {
		int i, j, k;

		if (a.size() == b.size()) {
			i = 0;
			j = b.size() - 1;
			while (j >= 0) {
				if (a[i] != b[j]) return false;
				i++;
				j--;
			}
		} else if (a.size() > b.size()) {
			i = 0;
			j = b.size() - 1;
			while (j >= 0) {
				if (a[i] != b[j]) return false;
				i++;
				j--;
			}
			j = a.size() - 1;
			while (i < j) {
				if (a[i] != a[j]) return false;
				i++;
				j--;
			}
		} else {
			i = 0;
			j = b.size() - 1;
			while (i < a.size()) {
				if (a[i] != b[j]) return false;
				i++;
				j--;
			}
			i = 0;
			while (i < j) {
				if (b[i] != b[j]) return false;
				i++;
				j--;
			}
		}

		return true;
	}
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
		vector<int> arr;
		int i, j;

		for (i = 0; i < words.size(); i++) {
			for (j = 0; j < words.size(); j++) {
				if (i == j) continue;
				if (isPalindrome(words[i], words[j]) == true) {
					arr.clear();
					arr.push_back(i);
					arr.push_back(j);
					result.push_back(arr);
				}
			}
		}

		return result;
    }
};

void printResult(vector<vector<int>>& result) {
	int i, j;

	cout << "[";
	for (i = 0; i < result.size(); i++) {
		cout << "[";
		for (j = 0; j < result[i].size(); j++) {
			cout << result[i][j];
			if (j < result[i].size() - 1) cout << ", ";
		}
		cout << "]";
		if (i < result.size() - 1) cout << ", ";
	}
	cout << "]\n";
}

int main(int argc, char* argv[]) {
	Solution s;
	vector<string> words;
	vector<vector<int>> result;

	words.clear();
	words.push_back("bat");
	words.push_back("tab");
	words.push_back("cat");
	result = s.palindromePairs(words);
	printResult(result);

	words.clear();
	words.push_back("abcd");
	words.push_back("dcba");
	words.push_back("lls");
	words.push_back("s");
	words.push_back("sssll");
	result = s.palindromePairs(words);
	printResult(result);

	return 0;
}

/*
["bat", "tab", "cat"]
=====
[[0, 1], [1, 0]]

["abcd", "dcba", "lls", "s", "sssll"]
=====
[[0, 1], [1, 0], [3, 2], [2, 4]]
*/
