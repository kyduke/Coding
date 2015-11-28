// http://codeforces.com/problemset/problem/600/A

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str;

bool isNumbers(string str) {
	int i;
	char c;

	if (str.size() == 1) {
		c = str[0];
		if (c >= '0' && c <= '9') return true;
		return false;
	}

	if (str[0] == '0') return false;

	for (i = 0; i < str.size(); i++) {
		c = str[i];
		if (c < '0' || c > '9') return false;
	}

	return true;
}

int main(int argc, char* argv[]) {
	vector<string> numbers;
	vector<string> others;
	string sub;
	int i, start;
	char c;

	cin >> str;
	str += ',';

	start = 0;
	for (i = 0; i < str.size(); i++) {
		c = str[i];
		if (c == ',' || c == ';') {
			if (start == i) {
				others.push_back("");
			} else {
				sub = str.substr(start, i - start);
				if (isNumbers(sub) == true) {
					numbers.push_back(sub);
				} else {
					others.push_back(sub);
				}
			}
			start = i + 1;
		}
	}

	if (numbers.size() == 0) {
		cout << "-\n";
	} else {
		cout << "\"";
		for (i = 0; i < numbers.size() - 1; i++) {
			cout << numbers[i] << ",";
		}
		cout << numbers[numbers.size() - 1] << "\"\n";
	}

	if (others.size() == 0) {
		cout << "-\n";
	} else {
		cout << "\"";
		for (i = 0; i < others.size() - 1; i++) {
			cout << others[i] << ",";
		}
		cout << others[others.size() - 1] << "\"\n";
	}

	return 0;
}

/*
aba,123;1a;0
=====
"123,0"
"aba,1a"

1;;01,a0,
=====
"1"
",01,a0,"

1
=====
"1"
-

a
=====
-
"a"
*/
