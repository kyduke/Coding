// https://www.hackerrank.com/challenges/cipher

#include <iostream>
#include <string>

using namespace std;

void solve(string& str, int n, int k) {
	int i, j, c, p;
	string result;

	result = "";
	c = 0;
	for (i = 0, j = -k; i < n; i++, j++) {
		if (j >= 0) {
			p = result[j] - '0';
			c ^= p;
		}
		p = str[i] - '0';
		p ^= c;
		cout << p;
		result += p + '0';
		if (i < n) {
			c ^= p;
		}
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	int n, k;
	string str;

	cin >> n >> k;
	cin >> str;
	solve(str, n, k);

	return 0;
}

/*
7 4
1110100110
=====
1001010

6 2
1110001
=====
101111
*/
