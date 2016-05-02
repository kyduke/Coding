// Google Code Jamp Round 1B 2016 Problem B. Close Match

#include <iostream>
#include <string>

using namespace std;

string diff(string a, string b) {
	string x, y, z;
	int i, m;

	x = a;
	y = b;
	if (a < b) {
		x = b;
		y = a;
	}

	m = 0;
	z = a;
	for (i = a.size() - 1; i >= 0; i--) {
		m += x[i] - y[i];
		if (m < 0) {
			z[i] = (m + 10) + '0';
			m = -1;
		} else {
			z[i] = m + '0';
			m = 0;
		}
	}

	return z;
}

pair<string, string> findSmall(pair<string, string> a, pair<string, string> b) {
	pair<string, string> result;
	string diffA, diffB;

	diffA = diff(a.first, a.second);
	diffB = diff(b.first, b.second);
	result = a;
	if (diffA > diffB) {
		result = b;
	} else if (diffA == diffB) {
		if (a.first > b.first) {
			result = b;
		} else if (a.first == b.first && a.second > b.second) {
			result = b;
		}
	}

	return result;
}

pair<string, string> makeBigger(string a, string b, bool left) {
	pair<string, string> result;
	char x, y;
	int i;

	if (left) {
		x = '0';
		y = '9';
	} else {
		x = '9';
		y = '0';
	}

	result.first = a;
	result.second = b;
	for (i = 0; i < a.size(); i++) {
		if (a[i] == '?') result.first[i] = x;
		if (b[i] == '?') result.second[i] = y;
	}

	return result;
}

pair<string, string> makeEqual(string a, string b, int idx) {
	pair<string, string> result, temp;

	if (idx == a.size()) {
		result.first = a;
		result.second = b;
		return result;
	}

	if (a[idx] == '?' && b[idx] == '?') {
		a[idx] = '0';
		b[idx] = '0';
		result = makeEqual(a, b, idx + 1);

		a[idx] = '1';
		b[idx] = '0';
		result = findSmall(result, makeBigger(a, b, true));

		a[idx] = '0';
		b[idx] = '1';
		result = findSmall(result, makeBigger(a, b, false));

		a[idx] = '?';
		b[idx] = '?';
	} else if (a[idx] == '?' && b[idx] != '?') {
		a[idx] = b[idx];
		result = makeEqual(a, b, idx + 1);

		if (b[idx] != '9') {
			a[idx] = b[idx] + 1;
			result = findSmall(result, makeBigger(a, b, true));
		}

		if (b[idx] != '0') {
			a[idx] = b[idx] - 1;
			result = findSmall(result, makeBigger(a, b, false));
		}

		a[idx] = '?';
	} else if (a[idx] != '?' && b[idx] == '?') {
		b[idx] = a[idx];
		result = makeEqual(a, b, idx + 1);

		if (a[idx] != '9') {
			b[idx] = a[idx] + 1;
			result = findSmall(result, makeBigger(a, b, false));
		}

		if (a[idx] != '0') {
			b[idx] = a[idx] - 1;
			result = findSmall(result, makeBigger(a, b, true));
		}

		b[idx] = '?';
	} else if (a[idx] == b[idx]) {
		result = makeEqual(a, b, idx + 1);
	} else {
		if (a[idx] > b[idx]) {
			result = makeBigger(a, b, true);
		} else {
			result = makeBigger(a, b, false);
		}
	}

	return result;
}

void solve(string a, string b) {
	pair<string, string> result;

	result = makeEqual(a, b, 0);

	cout << result.first << " " << result.second;
}

int main(int argc, char* argv[]) {
	int T, t;
	string a, b;

	cin >> T;
	t = 0;
	while (t < T) {
		cin >> a >> b;
		t++;
		cout << "Case #" << t << ": ";
		solve(a, b);
		cout << "\n";
	}

	return 0;
}

/*
4
1? 2?
?2? ??3
? ?
?5 ?0
=====
Case #1: 19 20
Case #2: 023 023
Case #3: 0 0
Case #4: 05 00

3
93 ?8
?9 ?0
??9 6?1
=====
98 88
09 10
599 601
*/
