// Facebook HackerCup 2017 C

#include <iostream>
#include <map>
#include <string>

using namespace std;

map<int, double> dice4[21];
map<int, double> dice6[21];
map<int, double> dice8[21];
map<int, double> dice10[21];
map<int, double> dice12[21];
map<int, double> dice20[21];

void preProcess() {
	map<int, double>::iterator itP, it;
	int i, j, n;
	double c, y;
	
	dice4[0].insert(make_pair(0, 1.0));
	y = 4.0;
	for (i = 0; i < 20; i++) {
		for (itP = dice4[i].begin(); itP != dice4[i].end(); itP++) {
			n = itP->first;
			c = itP->second / y;
			for (j = 1; j <= 4; j++) {
				it = dice4[i + 1].find(n + j);
				if (it == dice4[i + 1].end()) {
					dice4[i + 1].insert(make_pair(n + j, c));
				} else {
					it->second += c;
				}
			}
		}
	}
	
	dice6[0].insert(make_pair(0, 1.0));
	y = 6.0;
	for (i = 0; i < 20; i++) {
		for (itP = dice6[i].begin(); itP != dice6[i].end(); itP++) {
			n = itP->first;
			c = itP->second / y;
			for (j = 1; j <= 6; j++) {
				it = dice6[i + 1].find(n + j);
				if (it == dice6[i + 1].end()) {
					dice6[i + 1].insert(make_pair(n + j, c));
				} else {
					it->second += c;
				}
			}
		}
	}
	
	dice8[0].insert(make_pair(0, 1.0));
	y = 8.0;
	for (i = 0; i < 20; i++) {
		for (itP = dice8[i].begin(); itP != dice8[i].end(); itP++) {
			n = itP->first;
			c = itP->second / y;
			for (j = 1; j <= 8; j++) {
				it = dice8[i + 1].find(n + j);
				if (it == dice8[i + 1].end()) {
					dice8[i + 1].insert(make_pair(n + j, c));
				} else {
					it->second += c;
				}
			}
		}
	}
	
	dice10[0].insert(make_pair(0, 1.0));
	y = 10.0;
	for (i = 0; i < 20; i++) {
		for (itP = dice10[i].begin(); itP != dice10[i].end(); itP++) {
			n = itP->first;
			c = itP->second / y;
			for (j = 1; j <= 10; j++) {
				it = dice10[i + 1].find(n + j);
				if (it == dice10[i + 1].end()) {
					dice10[i + 1].insert(make_pair(n + j, c));
				} else {
					it->second += c;
				}
			}
		}
	}
	
	dice12[0].insert(make_pair(0, 1.0));
	y = 12.0;
	for (i = 0; i < 20; i++) {
		for (itP = dice12[i].begin(); itP != dice12[i].end(); itP++) {
			n = itP->first;
			c = itP->second / y;
			for (j = 1; j <= 12; j++) {
				it = dice12[i + 1].find(n + j);
				if (it == dice12[i + 1].end()) {
					dice12[i + 1].insert(make_pair(n + j, c));
				} else {
					it->second += c;
				}
			}
		}
	}
	
	dice20[0].insert(make_pair(0, 1.0));
	y = 20.0;
	for (i = 0; i < 20; i++) {
		for (itP = dice20[i].begin(); itP != dice20[i].end(); itP++) {
			n = itP->first;
			c = itP->second / y;
			for (j = 1; j <= 20; j++) {
				it = dice20[i + 1].find(n + j);
				if (it == dice20[i + 1].end()) {
					dice20[i + 1].insert(make_pair(n + j, c));
				} else {
					it->second += c;
				}
			}
		}
	}
}

double solve(string str, int h) {
	map<int, double>::iterator it;
	int i, x, y, z, sign;
	double ans;

	x = 0;
	for (i = 0; i < str.size(); i++) {
		if (str[i] == 'd') break;
		x = x * 10 + (str[i] - '0');
	}

	y = 0;
	for (; i < str.size(); i++) {
		if (str[i] == 'd') continue;
		if (str[i] == '-' || str[i] == '+') break;
		y = y * 10 + (str[i] - '0');
	}

	z = 0;
	sign = 1;
	for (; i < str.size(); i++) {
		if (str[i] == '-') {
			sign = -1;
			continue;
		} else if (str[i] == '+') {
			continue;
		}
		z = z * 10 + (str[i] - '0');
	}
	z *= sign;

	h -= z;

	ans = 0.0;
	if (y == 4) {
		for (it = dice4[x].begin(); it != dice4[x].end(); it++) {
			if (it->first < h) continue;
			ans += it->second;
		}
	} else if (y == 6) {
		for (it = dice6[x].begin(); it != dice6[x].end(); it++) {
			if (it->first < h) continue;
			ans += it->second;
		}
	} else if (y == 8) {
		for (it = dice8[x].begin(); it != dice8[x].end(); it++) {
			if (it->first < h) continue;
			ans += it->second;
		}
	} else if (y == 10) {
		for (it = dice10[x].begin(); it != dice10[x].end(); it++) {
			if (it->first < h) continue;
			ans += it->second;
		}
	} else if (y == 12) {
		for (it = dice12[x].begin(); it != dice12[x].end(); it++) {
			if (it->first < h) continue;
			ans += it->second;
		}
	} else if (y == 20) {
		for (it = dice20[x].begin(); it != dice20[x].end(); it++) {
			if (it->first < h) continue;
			ans += it->second;
		}
	}

	return ans;
}

int main(int argc, char* argv[]) {
	int t, ti, h, s;
	double ans;
	string str;

	preProcess();

	cin >> t;
	for (ti = 1; ti <= t; ti++) {
		ans = 0.0;

		cin >> h >> s;
		while (s--) {
			cin >> str;
			ans = max(ans, solve(str, h));
		}

		cout << "Case #" << ti << ": ";
		printf("%.6f", ans);
		if (ti < t) cout << "\n";
	}

	return 0;
}

/*
5
2 2
2d4 1d8
10 2
10d6-10 1d6+1
8 3
1d4+4 2d4 3d4-4
40 3
10d4 5d8 2d20
10 4
1d10 1d10+1 1d10+2 1d10+3
=====
Case #1: 1.000000
Case #2: 0.998520
Case #3: 0.250000
Case #4: 0.002500
Case #5: 0.400000
*/
