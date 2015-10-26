// http://codeforces.com/problemset/problem/591/B

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 200000;


char str[SIZE + 1];
int n, m;

void solve() {
	pair<char, vector<int>> chars[26];
	int i, j;
	char a, b;

	for (i = 0; i < n; i++) {
		chars[str[i] - 'a'].first = str[i];
		chars[str[i] - 'a'].second.push_back(i);
	}

	while (m--) {
		cin >> a >> b;
		if (a == b) continue;
		for (i = 0; i < 26; i++) {
			if (chars[i].first == a) {
				chars[i].first = b;
			} else if (chars[i].first == b) {
				chars[i].first = a;
			}
		}
	}

	for (i = 0; i < 26; i++) {
		for (j = 0; j < chars[i].second.size(); j++) {
			str[chars[i].second[j]] = chars[i].first;
		}
	}
}

int main(int argc, char* argv[]) {
	cin >> n >> m;
	cin >> str;

	solve();

	cout << str << "\n";

	return 0;
}

/*
6 1
police
p m
=====
molice

11 6
abacabadaba
a b
b c
a d
e g
f a
b b
=====
cdcbcdcfcdc
*/
