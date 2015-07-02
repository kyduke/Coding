// http://codeforces.com/problemset/problem/556/A

#include <iostream>
#include <string>

using namespace std;

int caseOfZerosAndOnes(int n, string& str) {
	int i, c;

	c = 0;
	for (i = 0; i < n; i++) {
		if (str[i] == '0') {
			c++;
		} else {
			c--;
		}
	}

	if (c < 0) c *= -1;

	return c;
}

int main() {
	int n;
	string str;

	cin >> n;
	cin >> str;

	cout << caseOfZerosAndOnes(n, str) << "\n";

	return 0;
}

/*
4
1100
=====
0

5
01010
=====
1

8
11101111
=====
6
*/
