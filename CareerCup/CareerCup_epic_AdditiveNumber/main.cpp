//http://www.careercup.com/question?id=5716152036622336
#include <iostream>
#include <string>

using namespace std;

string intToString(int n) {
	string result = "";

	if (n == 0) return "0";
	if (n < 0) n = -n;

	while (n) {
		result.insert(0, 1, n % 10 + '0');
		n /= 10;
	}

	return result;
}

int stringToInt(string& s) {
	int i, result;

	i = 0;
	result = 0;
	while (i < s.size()) {
		result = result * 10 + (s[i] - '0');
		i++;
	}

	return result;
}

bool isAdditive(string n) {
	int a, b, c, i, j, k;
	string s, t, r;

	if (n.size() == 0) return true;
	if (n.size() < 3) return false;

	for (i = 1; i <= n.size(); i++) {
		a = stringToInt(n.substr(0, i));
		s = n.substr(i);
		for (j = 1; j <= s.size(); j++) {
			b = stringToInt(s.substr(0, j));
			t = s.substr(j);
			for (k = 1; k <= t.size(); k++) {
				c = stringToInt(t.substr(0, k));
				r = t.substr(k);
				if (a + b == c && isAdditive(r)) {
					cout << a << " + " << b << " = " << c << "\n";
					return true;
				}
			}
		}
	}

	return false;
}

int main(int argc, char* argv[]) {
	cout << isAdditive(intToString(123459)) << "\n";
	cout << isAdditive(intToString(314538)) << "\n";
	cout << isAdditive(intToString(122436)) << "\n";
	cout << isAdditive(intToString(0)) << "\n";
	cout << isAdditive(intToString(12345)) << "\n";

	return 0;
}
