// http://careercup.com/question?id=5193265659772928

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool verify(string& str) {
	stack<char> s;
	int i;

	for (i = 0; i < str.size(); i++) {
		if (str[i] == '<' || str[i] == '[' || str[i] == '(') {
			s.push(str[i]);
		} else if (str[i] == '>') {
			if (s.size() == 0 || s.top() != '<') return false;
			s.pop();
		} else if (str[i] == ']') {
			if (s.size() == 0 || s.top() != '[') return false;
			s.pop();
		} else if (str[i] == ')') {
			if (s.size() == 0 || s.top() != '(') return false;
			s.pop();
		}
	}
	if (s.size() > 0) return false;

	return true;
}

int main(int argc, char* argv[]) {
	string str;

	str = "<ad675+-fkmfd>";
	cout << str << ": " << verify(str) << "\n";

	str = "<[((kskfhdbh7)";
	cout << str << ": " << verify(str) << "\n";

	str = "[<<((shfs8))>>]";
	cout << str << ": " << verify(str) << "\n";

	return 0;
}
