// http://codeforces.com/contest/707/problem/A

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int n, m, i;
	char c;
	bool flag;

	cin >> n >> m;
	flag = true;
	for (i = 0; i < n * m; i++) {
		cin >> c;
		if (c == 'C' || c == 'M' || c == 'Y') {
			flag = false;
		}
	}

	if (flag == true) {
		cout << "#Black&White";
	} else {
		cout << "#Color";
	}

	return 0;
}

/*
2 2
C M
Y Y
=====
#Color

3 2
W W
W W
B B
=====
#Black&White

1 1
W
=====
#Black&White
*/
