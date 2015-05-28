//http://codeforces.com/problemset/problem/548/A

#include <iostream>
#include <string.h>

using namespace std;

bool isPalindrome(char *s) {
	int i, l, h;

	l = strlen(s);
	h = l / 2;
	i = 0;
	while (i <= h) {
		if (s[i] != s[l - i - 1]) return false;
		i++;
	}

	return true;
}

void solve(char *s, int k) {
	char message[1001];
	int i, t, l;

	l = strlen(s);
	if (l % k) {
		cout << "NO\n";
		return;
	}

	t = l / k;
	for (i = 0; i < l; i += t) {
		strncpy(message, &s[i], t);
		message[i + t] = '\0';
		if (!isPalindrome(message)) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

int main(int argc, char *argv[]) {
	char buffer[1001];
	int k;

	cin >> buffer >> k;

	solve(buffer, k);

	return 0;
}
