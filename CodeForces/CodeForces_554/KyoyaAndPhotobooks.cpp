// http://codeforces.com/problemset/problem/554/A

#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char* argv[]) {
	char str[21];

	cin >> str;

	cout << (26 * (strlen(str) + 1) - strlen(str)) << "\n";

	return 0;
}

/*
a
=====
51

hi
=====
76
*/
