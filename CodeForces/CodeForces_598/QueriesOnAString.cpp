// http://codeforces.com/contest/598/problem/B

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	int m, l, r, k, len, i;
	string str, sub;

	cin >> str;
	cin >> m;
	while (m--) {
		cin >> l >> r >> k;
		l--;
		r--;
		len = r - l + 1;
		k = k % (len);
		sub = str.substr(l, len);

		i = len - k;
		len = len - k;
		while (k--) {
			str[l] = sub[i];
			l++;
			i++;
		}

		i = 0;
		while (len--) {
			str[l] = sub[i];
			l++;
			i++;
		}
	}
	cout << str << "\n";

	return 0;
}

/*
abacaba
2
3 6 1
1 4 2
=====
baabcaa
*/
