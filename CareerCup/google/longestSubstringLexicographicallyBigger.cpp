// https://careercup.com/question?id=5731367452147712

#include <iostream>
#include <string>

using namespace std;

void printLongestSubstringLexicographicallyBigger(string str) {
	int i, j;
	bool found;

	for (i = 1; i < str.size(); i++) {
		found = true;
		for (j = 0; i + j < str.size(); j++) {
			if (str[j] > str[i + j]) {
				found = false;
				break;
			} else if (str[j] < str[i + j]) {
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
	cout << str << "\n";
	printLongestSubstringLexicographicallyBigger(str);

	str = "sssssssssssssssssat";
	cout << str << "\n";
	printLongestSubstringLexicographicallyBigger(str);

	str = "sstaaaa";
	cout << str << "\n";
	printLongestSubstringLexicographicallyBigger(str);

	str = "tedisanonprofitdevotedtoideasworthspreading";
	cout << str << "\n";
	printLongestSubstringLexicographicallyBigger(str);

	return 0;
}
