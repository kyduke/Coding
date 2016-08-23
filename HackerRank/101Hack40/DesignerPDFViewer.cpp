// https://www.hackerrank.com/contests/101hack40/challenges/designer-pdf-viewer

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int h[26];
	char str[12];
	int i, maxHeight;

	for (i = 0; i < 26; i++) {
		cin >> h[i];
	}
	cin >> str;

	i = 0;
	maxHeight = 0;
	while (str[i] != 0) {
		maxHeight = max(maxHeight, h[str[i] - 'a']);
		i++;
	}

	cout << maxHeight * i;

	return 0;
}

/*
1 3 1 3 1 4 1 3 2 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
abc
=====
9
*/
