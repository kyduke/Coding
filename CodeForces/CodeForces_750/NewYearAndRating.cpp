// CodeForces Good Bye 2016 C
// http://codeforces.com/contest/750/problem/C

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n, c, d, s, e;
	bool imp, inf;

	cin >> n;

	imp = false;
	inf = true;
	cin >> c >> d;
	if (d == 1) {
		s = 210000000;
		e = 1900;
	} else {
		s = 1899;
		e = -210000000;
		inf = false;
	}
	s += c;
	e += c;
	n--;
	while (n--) {
		cin >> c >> d;
		if (imp) continue;
		if (d == 1) {
			if (s < 1900) {
				imp = true;
				continue;
			}
			e = max(e, 1900);
		} else {
			if (e > 1899) {
				imp = true;
				continue;
			}
			s = min(s, 1899);
			inf = false;
		}
		s += c;
		e += c;
	}

	if (imp) {
		cout << "Impossible\n";
	} else if (inf) {
		cout << "Infinity\n";
	} else {
		cout << s << "\n";
	}

	return 0;
}

/*
3
-7 1
5 2
8 2
=====
1907

2
57 1
22 2
=====
Impossible

1
-5 1
=====
Infinity

4
27 2
13 1
-50 1
8 2
=====
1897
*/
