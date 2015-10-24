// http://careercup.com/question?id=5746818291859456

#include <iostream>

using namespace std;

bool validParenthesis(string str) {
	int i, n;

	i = 0;
	n = 0;
	while (i < str.size()) {
		if (str[i] == '(') {
			n++;
		} else if (str[i] == ')') {
			if (n == 0) return false;
			n--;
		}
		i++;
	}

	return (n == 0);
}

int main(int argc, char* argv[]) {
	cout << validParenthesis(")(((((") << "\n";
	cout << validParenthesis("(((((()") << "\n";
	cout << validParenthesis("(((((((((())))))))))") << "\n";
	cout << validParenthesis("(())())") << "\n";
	cout << validParenthesis("(()(())") << "\n";
	cout << validParenthesis("(()())") << "\n";

	return 0;
}
