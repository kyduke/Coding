// https://www.hackerrank.com/contests/hourrank-24/challenges/strong-password/problem

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	int n, i, ans;
	string str;
	char c;
	bool dFlag, aFlag, AFlag, sFlag;

	cin >> n;
	cin >> str;

	dFlag = false;
	aFlag = false;
	AFlag = false;
	sFlag = false;

	for (i = 0; i < n; i++) {
		c = str[i];
		if (c >= '0' && c <= '9') {
			dFlag = true;
		} else if (c >= 'a' && c <= 'z') {
			aFlag = true;
		} else if (c >= 'A' && c <= 'Z') {
			AFlag = true;
		} else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '+') {
			sFlag = true;
		}
	}

	ans = 0;
	if (dFlag == false) ans++;
	if (aFlag == false) ans++;
	if (AFlag == false) ans++;
	if (sFlag == false) ans++;

	while (n + ans < 6) ans++;

	cout << ans << "\n";

	return 0;
}

/*
3
Ab1
=====
3

11
#HackerRank
=====
1
*/
