// http://codeforces.com/contest/629/problem/B

#include <iostream>
#include <set>

using namespace std;

const int SIZE = 5000;

struct Days {
	char c;
	int s;
	int e;
};

Days friends[SIZE];

int solve(int n) {
	set<int> days;
	set<int>::iterator it;
	int i, x, y, ret;

	ret = 0;

	for (i = 0; i < n; i++) {
		days.insert(friends[i].s);
		days.insert(friends[i].e);
	}

	for (it = days.begin(); it != days.end(); it++) {
		x = 0;
		y = 0;
		for (i = 0; i < n; i++) {
			if (friends[i].s <= *it && friends[i].e >= *it) {
				if (friends[i].c == 'M') {
					x++;
				} else {
					y++;
				}
			}
		}
		ret = max(ret, min(x, y));
	}

	return ret * 2;
}

int main(int argc, char* argv[]) {
	int n, i;
	char c;
	

	cin >> n;
	i = 0;
	while (i < n) {
		cin >> friends[i].c >> friends[i].s >> friends[i].e;
		i++;
	}

	cout << solve(n) << "\n";
	
	return 0;
}

/*
4
M 151 307
F 343 352
F 117 145
M 24 128
=====
2

6
M 128 130
F 128 131
F 131 140
F 131 141
M 131 200
M 140 200
=====
4
*/
