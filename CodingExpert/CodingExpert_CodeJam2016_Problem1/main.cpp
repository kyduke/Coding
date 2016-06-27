// LGE CodeJam 2016 Problem 1

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

const int SIZE = 50001;

int solve(map<int, vector<int>>& m, int n) {
	map<int, vector<int>>::iterator it;
	int i, c;

	c = 0;
	it = m.find(n);
	if (it == m.end()) return 1;
	for (i = 0; i < it->second.size(); i++) {
		c = max(c, solve(m, it->second[i]) + 1);
	}

	return c;
}

int main(int argc, char* argv[]) {
	map<int, vector<int>> m;
	vector<int> v;
	map<int, vector<int>>::iterator it;
	set<int> parents;
	set<int>::iterator sit;
	int childs[SIZE];
	int t, n, a, b, p;

	cin >> t;
	while (t--) {
		m.clear();
		parents.clear();
		memset(childs, 0, SIZE);
		cin >> n;
		while (--n) {
			cin >> a >> b;
			it = m.find(a);
			if (it == m.end()) {
				v.clear();
				v.push_back(b);
				m.insert(make_pair(a, v));
			} else {
				it->second.push_back(b);
			}
			parents.insert(a);
			childs[b] = 1;
		}
		for (sit = parents.begin(); sit != parents.end(); sit++) {
			if (childs[*sit] == 0) {
				p = *sit;
				break;
			}
		}
		cout << solve(m, p) << "\n";
	}

	return 0;
}

/*
2
6
3 5
1 2
4 1
3 4
4 6
10
5 1
4 5
4 6
6 2
5 8
6 3
7 10
5 9
4 7
=====
4
3
*/
