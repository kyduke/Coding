//http://codeforces.com/contest/550/problem/A

#include <iostream>
#include <string.h>

using namespace std;

const int LENGTH = 100005;

int main(int argc, char* argv[]) {
	char s[LENGTH];
	int i, len, n;
	bool ab, ba;

	cin >> &(s[1]);
	s[0] = ' ';
	len = strlen(s);
	s[len] = ' ';
	s[len + 1] = ' ';
	s[len + 2] = ' ';
	s[len + 3] = '\0';

	for (i = 1; i < len; i++) {
		if (s[i] == 'A' && (s[i - 1] == 'B' || s[i + 1] == 'B')) {
			continue;
		} else if (s[i] == 'B' && (s[i - 1] == 'A' || s[i + 1] == 'A')) {
			continue;
		} else {
			s[i] = ' ';
		}
	}

	ab = false;
	for (i = 0; i < len; i++) {
		if (s[i] == 'A' && (s[i - 1] == ' ' || s[i - 1] == 'A') && s[i + 1] == 'B' && s[i + 2] == ' ') {
			ab = true;
			s[i] = ' ';
			s[i + 1] = ' ';
		}
	}

	ba = false;
	for (i = 0; i < len; i++) {
		if (s[i] == 'B' && (s[i - 1] == ' ' || s[i - 1] == 'B') && s[i + 1] == 'A' && s[i + 2] == ' ') {
			ba = true;
			s[i] = ' ';
			s[i + 1] = ' ';
		}
	}

	if (ab && ba) {
		cout << "YES\n";
		return 0;
	}

	//ABABA or BABAB, continuous length more than 5
	n = 0;
	for (i = 0; i < len; i++) {
		if (s[i] == ' ') {
			n = 0;
		} else {
			n++;
			if (n >= 5) {
				cout << "YES\n";
				return 0;
			}
		}
	}

	//count ABA or BAB
	n = 0;
	if (ab || ba) n++;
	for (i = 0; i < len; i++) {
		if ((s[i] == 'A' || s[i] =='B') && s[i - 1] == ' ') {
			n++;
			if (n >= 2) {
				cout << "YES\n";
				return 0;
			}
		}
	}

	cout << "NO\n";

	return 0;
}

/*
ABA
=====
NO

BACFAB
=====
YES

AXBYBXA
=====
NO
*/
