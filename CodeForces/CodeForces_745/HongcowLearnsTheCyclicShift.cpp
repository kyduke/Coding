// http://codeforces.com/problemset/problem/745/A

#include <iostream>
#include <string>

using namespace std;

int solve(string& s) {
	string t;
	int i, k, ans;

	t = s + s;

	ans = 1;
	while (ans <= s.size()) {
		k = 0;
		for (i = 0; i < s.size(); i++) {
			if (s[i] == t[i + ans]) k++;
		}
		if (k == s.size()) break;
		ans++;
	}

	return ans;
}

int main(int argc, char* argv) {
	string s;

	cin >> s;

	cout << solve(s) << "\n";

	return 0;
}

/*
abcd
=====
4

bbb
=====
1

yzyz
=====
2
*/
