// http://codeforces.com/problemset/problem/572/B

#include <iostream>
#include <map>

using namespace std;

map<int, pair<int, char>> sells;
map<int, pair<int, char>> buys;
int s;

void solve() {
	map<int, pair<int, char>> result;
	map<int, pair<int, char>>::iterator it;
	map<int, pair<int, char>>::reverse_iterator rit;
	int i;

	i = 0;
	it = sells.begin();
	while (it != sells.end()) {
		result.insert(*it);
		it++;
		i++;
		if (i >= s) break;
	}

	i = 0;
	rit = buys.rbegin();
	while (rit != buys.rend()) {
		result.insert(*rit);
		rit++;
		i++;
		if (i >= s) break;
	}

	rit = result.rbegin();
	while (rit != result.rend()) {
		cout << rit->second.second << " " << rit->first << " " << rit->second.first << "\n";
		rit++;
	}
}

int main(int argc, char* argv[]) {
	map<int, pair<int, char>>::iterator it;
	int n, p, q;
	char d;

	cin >> n >> s;

	while (n--) {
		cin >> d >> p >> q;
		if (d == 'S') {
			it = sells.find(p);
			if (it == sells.end()) {
				sells.insert(make_pair(p, make_pair(q, d)));
			} else {
				it->second.first += q;
			}
		} else {
			it = buys.find(p);
			if (it == buys.end()) {
				buys.insert(make_pair(p, make_pair(q, d)));
			} else {
				it->second.first += q;
			}
		}
	}

	solve();

	return 0;
}

/*
6 2
B 10 3
S 50 2
S 40 1
S 50 6
B 20 4
B 25 10
=====
S 50 8
S 40 1
B 25 10
B 20 4
*/
