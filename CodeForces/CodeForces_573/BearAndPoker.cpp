// http://codeforces.com/problemset/problem/573/A

#include <iostream>

using namespace std;

int getRemain(int n) {
	while (n % 2 == 0) {
		n /= 2;
	}
	while (n % 3 == 0) {
		n /= 3;
	}

	return n;
}

int main(int argc, char* argv[]) {
	int n, a, r;
	bool result;

	cin >> n;

	cin >> a;
	r = getRemain(a);
	n--;

	result = true;
	while (n--) {
		cin >> a;
		if (result == true && getRemain(a) != r) result = false;
	}

	if (result == true) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	return 0;
}

/*
4
75 150 75 50
=====
Yes

3
100 150 250
=====
No
*/
