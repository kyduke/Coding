// http://codeforces.com/problemset/problem/595/A

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int n, m, i, x, y, result;

	result = 0;
	cin >> n >> m;
	while (n--) {
		i = 0;
		while (i < m) {
			cin >> x >> y;
			if (x + y > 0) result++;
			i++;
		}
	}

	cout << result << "\n";

	return 0;
}

/*
2 2
0 0 0 1
1 0 1 1
=====
3

1 3
1 1 0 1 0 0
=====
2
*/
