// https://algospot.com/judge/problem/read/PALINDROMIZE

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> KMPFail(string& str) {
	vector<int> fail;
	int i, pos;

	fail.assign(str.size() + 1, -1);

	for (i = 1; i <= str.size(); i++) {
		pos = fail[i - 1];
		while (pos != -1 && str[pos] != str[i - 1]) {
			pos = fail[pos];
		}
		fail[i] = pos + 1;
	}

	return fail;
}

int solve(string& str) {
	vector<int> fail;
	string rev;
	int strPos, revPos;
	
	rev = str;
	reverse(rev.begin(), rev.end());

	fail = KMPFail(rev);

	strPos = 0;
	revPos = 0;
	while (strPos < str.size()) {
		while (revPos != -1 && rev[revPos] != str[strPos]) {
			revPos = fail[revPos];
		}
		revPos++;
		strPos++;
	}

	return str.size() + str.size() - revPos;
}

int main(int argc, char* argv[]) {
	int c;
	string str;

	cin >> c;
	while (c--) {
		cin >> str;

		cout << solve(str) << "\n";
	}

	return 0;
}

/*
3
there
amanaplanacanal
xyz
=====
7
21
5
*/
