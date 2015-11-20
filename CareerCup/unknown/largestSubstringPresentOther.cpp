// http://careercup.com/question?id=5740247847534592

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string latgestSubstringPresentOther(string s1, string s2) {
	vector<int> arr(s1.size() + 1, 0);
	int present[256] = {0, };
	int i, start, maxLength, length;

	for (i = 0; i < s2.size(); i++) {
		present[ s2[i] ] = 1;
	}

	for (i = 0; i < s1.size(); i++) {
		arr[i] = present[ s1[i] ];
	}

	start = 0;
	maxLength = 0;
	length = 0;
	for (i = 0; i < arr.size(); i++) {
		if (arr[i] == 0) {
			if (maxLength < length) {
				maxLength = length;
				start = i - length;
			}
			length = 0;
			continue;
		}
		length++;
	}

	return s1.substr(start, maxLength);
}

int main(int argc, char* argv[]) {
	cout << latgestSubstringPresentOther("CareerCup is the world's biggest and best source for software engineering interview preparation.", "unknown Interview Question for SDE-2s") << "\n";

	cout << latgestSubstringPresentOther("abcdefghijklmnopqrstuvwxyz", "xcobra") << "\n";

	return 0;
}
