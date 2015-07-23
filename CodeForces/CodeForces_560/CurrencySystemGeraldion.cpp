// http://codeforces.com/problemset/problem/560/A

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int n, t, result;

	result = 1;

	cin >> n;
	while (n--) {
		cin >> t;
		if (t == 1) result = -1;
	}

	cout << result << "\n";

	return 0;
}

/*
5
1 2 3 4 5
=====
-1

1
2
=====
1
*/
