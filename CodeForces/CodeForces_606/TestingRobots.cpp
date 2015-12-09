// http://codeforces.com/contest/606/problem/B

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cells[500][500];

int main(int argc, char* argv[]) {
	int x, y, a, b, i, j, all;
	string str;

	cin >> x >> y >> a >> b;
	cin >> str;

	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			cells[i][j] = 1;
		}
	}
	all = x * y;

	a--;
	b--;
	cells[a][b] = 0;
	cout << 1 << " ";
	all--;
	i = 0;
	while (i < str.size() - 1) {
		if (str[i] == 'U') {
			if (a > 0) a--;
		} else if (str[i] == 'D') {
			if (a < x - 1) a++;
		} else if (str[i] == 'L') {
			if (b > 0) b--;
		} else if (str[i] == 'R') {
			if (b < y - 1) b++;
		}
		cout << cells[a][b] << " ";
		all -= cells[a][b];
		cells[a][b] = 0;
		i++;
	}

	cout << all << "\n";

	return 0;
}

/*
3 4 2 2
UURDRDRL
=====
1 1 0 1 1 1 1 0 6

2 2 2 2
ULD
=====
1 1 1 1
*/
