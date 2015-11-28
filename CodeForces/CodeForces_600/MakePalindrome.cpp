// http://codeforces.com/problemset/problem/600/C

#include <iostream>
#include <string.h>

using namespace std;

const int SIZE = 200001;

char str[SIZE];
int abc[26];
int n;

void solve() {
	int i, j, n, start, end;
	bool odd;

	n = strlen(str);
	if (n == 1) return;

	odd = false;
	if (n % 2 == 1) odd = true;

	for (i = 0; i < n; i++) {
		abc[ (str[i] - 'a') ]++;
	}

	start = 0;
	end = 25;
	while (start < end) {
		while (abc[start] % 2 == 0) {
			start++;
		}
		while (abc[end] % 2 == 0) {
			end--;
		}
		abc[start]++;
		abc[end]--;
		start++;
		end--;
	}

	if (odd == true) {
		for (i = 0; i < 26; i++) {
			if (abc[i] % 2 == 1) {
				str[n / 2] = i + 'a';
				abc[i]--;
				odd = false;
				break;
			}
		}
	}

	start = 0;
	end = n - 1;
	for (i = 0; i < 26; i++) {
		if (abc[i] == 0) continue;
		while (abc[i]) {
			str[start] = i + 'a';
			str[end] = i + 'a';
			abc[i] -= 2;
			start++;
			end--;
		}
	}
}

int main(int argc, char* argv[]) {
	cin >> str;

	solve();

	cout << str << "\n";

	return 0;
}

/*
aabc
======
abba

aabcd
======
abcba
*/
