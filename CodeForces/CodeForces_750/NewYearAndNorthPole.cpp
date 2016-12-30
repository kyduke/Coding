// CodeForces Good Bye 2016 B
// http://codeforces.com/contest/750/problem/B

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	int n, p, t;
	string s;
	bool flag;

	cin >> n;

	p = 0;
	flag = true;
	while (n--) {
		cin >> t >> s;
		if (s == "South") {
			p += t;
			if (p > 20000) {
				flag = false;
				p = 20000;
			}
		} else if (s == "North") {
			p -= t;
			if (p < 0) {
				flag = false;
				p = 0;
			}
		} else {
			if (p == 0 || p == 20000) {
				flag = false;
			}
		}
	}

	if (p == 0 && flag) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}

/*
5
7500 South
10000 East
3500 North
4444 West
4000 North
=====
YES

2
15000 South
4000 East
=====
NO

5
20000 South
1000 North
1000000 West
9000 North
10000 North
=====
YES

3
20000 South
10 East
20000 North
=====
NO

2
1000 North
1000 South
=====
NO

4
50 South
50 North
15000 South
15000 North
=====
YES
*/
