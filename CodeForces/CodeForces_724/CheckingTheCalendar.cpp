// http://codeforces.com/problemset/problem/724/A

#include <iostream>
#include <string>

using namespace std;

int weekdayToNumber(string str) {
	if(str == "monday") {
		return 0;
	} else if (str == "tuesday") {
		return 1;
	} else if (str == "wednesday") {
		return 2;
	} else if (str == "thursday") {
		return 3;
	} else if (str == "friday") {
		return 4;
	} else if (str == "saturday") {
		return 5;
	}
	return 6;
}

int main(int argc, char* argv[]) {
	string str;
	int a, b, c;

	cin >> str;
	a = weekdayToNumber(str);

	cin >> str;
	b = weekdayToNumber(str);

	c = (b - a + 7) % 7;

	if (c == 0 || c == 2 || c == 3) {
		cout << "YES";
	} else {
		cout << "NO";
	}

	return 0;
}


/*
monday
tuesday
=====
NO

sunday
sunday
=====
YES

saturday
tuesday
=====
YES
*/
