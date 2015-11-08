// https://leetcode.com/problems/remove-invalid-parentheses/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
	bool isValid(string s) {
		int i, n;

		n = 0;
		for (i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				n++;
			} else if (s[i] == ')') {
				if (n == 0) return false;
				n--;
			}
		}

		return n == 0;
	}
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> a, b, ret;
		int i, j, open, close;
		string temp;
		bool found;

		i = 0;
		while (i < s.size()) {
			if (s[i] == '(') break;
			if (s[i] == ')') {
				s.erase(i, 1);
				continue;
			}
			i++;
		}
		
		i = s.size() - 1;
		while (i >= 0) {
			if (s[i] == ')') break;
			if (s[i] == '(') s.erase(i, 1);
			i--;
		}

		a.push_back(s);
		found = false;
		while (found == false) {
			for (i = 0; i < a.size(); i++) {
				if (isValid(a[i])) {
					found = true;
					if (find(ret.begin(), ret.end(), a[i]) == ret.end()) ret.push_back(a[i]);
				} else {
					open = 0;
					close = 0;
					for (j = 0; j < a[i].size(); j++) {
						if (a[i][j] == '(') open++;
						else if (a[i][j] == ')') close++;
					}
					if (open > close) {
						for (j = 0; j < a[i].size(); j++) {
							if (a[i][j] == '(') {
								temp = a[i];
								temp.erase(j, 1);
								if (find(b.begin(), b.end(), temp) == b.end()) b.push_back(temp);
							}
						}
					} else if (open < close) {
						for (j = 0; j < a[i].size(); j++) {
							if (a[i][j] == ')') {
								temp = a[i];
								temp.erase(j, 1);
								if (find(b.begin(), b.end(), temp) == b.end()) b.push_back(temp);
							}
						}
					} else {
						for (j = 0; j < a[i].size(); j++) {
							if (a[i][j] == '(' || a[i][j] == ')') {
								temp = a[i];
								temp.erase(j, 1);
								if (find(b.begin(), b.end(), temp) == b.end()) b.push_back(temp);
							}
						}
					}
				}
			}
			a = b;
			b.clear();
		}

		return ret;
    }
};

void printArray(vector<string> arr) {
	int i;

	for (i = 0; i < arr.size(); i++) {
		cout << arr[i] << ", ";
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	Solution s;
	vector<string> arr;

	arr = s.removeInvalidParentheses("()())()");
	printArray(arr);

	arr = s.removeInvalidParentheses("(a)())()");
	printArray(arr);

	arr = s.removeInvalidParentheses(")(");
	printArray(arr);

	return 0;
}

/*
"()())()"
=====
["()()()", "(())()"]

"(a)())()"
=====
["(a)()()", "(a())()"]

")("
=====
[""]
*/
