// http://www.careercup.com/question?id=5758790009880576

#include <iostream>
#include <string>

using namespace std;

string removeDupAndSort(string& s) {
	int i, f[123] = {0, };
	string result;

	for (i = 0; i < s.size(); i++) f[ s[i] ] = 1;
	for (i = 'a'; i <= 'z'; i++) if (f[i] == 1) result.push_back(i);

	return result;
}

int main(int argc, char* argv[]) {
	string s = "bcabc";

	cout << removeDupAndSort(s) << "\n";

	return 0;
}
