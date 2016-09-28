// http://codeforces.com/problemset/problem/719/B

#include <iostream>
#include <string>

using namespace std;

int solve(string str, int n) {
	string copy;
	int ans, temp, i, b, r;

	ans = 0;

	// br...
	copy = str;
	temp = 0;
	if (n % 2) {
		b = n - 2;
		r = n - 1;
	} else {
		b = n - 1;
		r = n - 2;
	}
	for (i = 0; i < n; i++) {
		if (i % 2) {
			// r
			if (copy[i] == 'b') {
				while (r > i && copy[r] == 'b') {
					r -= 2;
				}
				if (r > i) {
					copy[r] = 'b';
				}
				temp++;
			}
		} else {
			// b
			if (copy[i] == 'r') {
				while (b > i && copy[b] == 'r') {
					b -= 2;
				}
				if (b > i) {
					copy[b] = 'r';
				}
				temp++;
			}
		}
	}
	ans = temp;

	// rb...
	copy = str;
	temp = 0;
	if (n % 2) {
		b = n - 1;
		r = n - 2;
	} else {
		b = n - 2;
		r = n - 1;
	}
	for (i = 0; i < n; i++) {
		if (i % 2) {
			// b
			if (copy[i] == 'r') {
				while (b > i && copy[b] == 'r') {
					b -= 2;
				}
				if (b > i) {
					copy[b] = 'r';
				}
				temp++;
			}
		} else {
			// r
			if (copy[i] == 'b') {
				while (r > i && copy[r] == 'b') {
					r -= 2;
				}
				if (r > i) {
					copy[r] = 'b';
				}
				temp++;
			}
		}
	}
	ans = min(ans, temp);

	return ans;
}

int main(int argc, char* argv[]) {
	string str;
	int n;

	cin >> n;
	cin >> str;

	cout << solve(str, n);

	return 0;
}

/*
5
rbbrr
=====
1

5
bbbbb
=====
2

3
rbr
=====
0
*/
