//http://codeforces.com/contest/550/problem/C

#include <iostream>
#include <string.h>

using namespace std;

const int LENGTH = 102;

void number2string(int n, char* s) {
	int d, k;

	if (n == 0) {
		s[0] = '0';
		s[1] = '\0';
		return;
	}

	d = 1;
	while (d < n) {
		d *= 10;
	}

	d /= 10;

	k = 0;
	while (d > 0) {
		s[k] = (n / d) + '0';
		n = n % d;
		d /= 10;
		k++;
	}
	s[k] = '\0';
}

void solve(char *s) {
	char t[10];
	int i, len, j, k, c;

	len = strlen(s);

	i = 0;
	while (i < 1000) {
		number2string(i, t);

		k = 1;
		c = 0;
		for (j = 0; j < strlen(t); j++) {
			while (k < len) {
				if (t[j] == s[k++]) {
					c++;
					break;
				}
			}
		}

		if (strlen(t) == c) {
			cout << "YES\n" << i << "\n";
			return;
		}

		i += 8;
	}
	
	cout << "NO\n";
}

int main(int argc, char* argv[]) {
	char s[LENGTH];
	int i;

	cin >> &(s[1]);
	s[0] = '0';

	solve(s);

	return 0;
}

/*
3454
=====
YES
344

10
=====
YES
0

111111
=====
NO
*/
