// Check Parentheses with ?(any)

#include <iostream>
#include <string>

using namespace std;

bool checkParentheses(string& str) {
	int i, a, b;

	a = 0;
	b = 0;
	for (i = 0; i < str.size(); i++) {
		if (str[i] == ')') {
			a++;
		} else {
			b++;
		}
		if (a > b) {
			return false;
		}
	}

	a = 0;
	b = 0;
	for (i = str.size() - 1; i >= 0; i--) {
		if (str[i] == '(') {
			a++;
		} else {
			b++;
		}
		if (a > b) {
			return false;
		}
	}

	return true;
}

int main(int argc, char* argv[]) {
	string str;

	str = "((()))";
	cout << str << ": " << checkParentheses(str) << "\n";

	str = "()()()";
	cout << str << ": " << checkParentheses(str) << "\n";

	str = "(?????";
	cout << str << ": " << checkParentheses(str) << "\n";

	str = "(?)))?";
	cout << str << ": " << checkParentheses(str) << "\n";

	return 0;
}
