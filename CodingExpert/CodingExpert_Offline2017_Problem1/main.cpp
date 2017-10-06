// LG CodeJam 2017 Final A

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	string str, strA, strB;
	int t, n, m, i, s, j;

	cin >> t;
	while (t--) {
		cin >> n >> m >> i >> s >> j;
		cin >> strA;
		cin >> strB;
		n += m;
		j--;
		str = strA + strB + strB + strA;
		if (j >= n * i) {
			cout << "X\n";
		} else {
			while (i > 1) {
				i--;
				j = j * 2 - s;
				m = n * i;
				if (j / m == 0 || j / m == 3) {
					s = 0;
				} else {
					s = 1;
				}
				j %= m;
			}
			j = j * 2 - s;
			cout << str[j] << "\n";
		}
	}

	return 0;
}

/*
3
8 6 2 0 1
AGCTTCGA
GGCCTA
4 4 2 1 100
ACTG
GTCA
3 3 3 0 2
AAA
TTT
=====
A
X
T
*/
