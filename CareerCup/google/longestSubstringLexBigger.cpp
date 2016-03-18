// https://careercup.com/question?id=5731367452147712

#include <iostream>
#include <string>

using namespace std;

void printLongestSubstringLexBigger(string str) {
	int i, j;
	bool found;

	for (i = 1; i < str.size(); i++) {
		found = false;
		for (j = 0; i + j < str.size(); j++) {
			if (str[j] > str[i + j]) {
				i += j;
				break;
			} else if (str[j] < str[i + j]) {
				found = true;
				break;
			}
		}

		if (found) {
			cout << str.substr(i) << "\n";
			break;
		}
	}
}

int main(int argc, char* argv[]) {
	string str;

	str = "sssss";
	cout << str << "\n"; //
	printLongestSubstringLexicographicallyBigger(str);

	str = "sssssssssssssssssat";
	cout << str << "\n"; //t
	printLongestSubstringLexicographicallyBigger(str);

	str = "sstaaaa";
	cout << str << "\n"; //staaaa
	printLongestSubstringLexicographicallyBigger(str);

	str = "dcbdcb";
	cout << str << "\n"; //
	printLongestSubstringLexicographicallyBigger(str);

	str = "dcbdcbx";
	cout << str << "\n"; //dcbx
	printLongestSubstringLexicographicallyBigger(str);

	str = "dcbdcbax";
	cout << str << "\n"; //x
	printLongestSubstringLexicographicallyBigger(str);

	str = "tedisanonprofitdevotedtoideasworthspreading";
	cout << str << "\n"; //votedtoideasworthspreading
	printLongestSubstringLexicographicallyBigger(str);

	return 0;
}
