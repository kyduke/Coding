// http://codeforces.com/contest/707/problem/B

#include <iostream>
#include <map>

using namespace std;

const int SIZE = 100000;

int n, k;
map<int, multimap<int, int>> distMap;
int cities[SIZE] = {0, };

int solve() {
	map<int, multimap<int, int>>::iterator it;
	multimap<int, int> s;
	multimap<int, int>::iterator sit;
	int answer, i;

	answer = -1;

	for (it = distMap.begin(); it != distMap.end(); it++) {
		s = it->second;
		for (sit = s.begin(); sit != s.end(); sit++) {
			if (cities[sit->first] + cities[sit->second] == 1) return it->first;
		}
	}

	return answer;
}

int main(int argc, char* argv[]) {
	map<int, multimap<int, int>>::iterator it;
	multimap<int, int> s;
	int i, m, u, v, a;
	
	cin >> n >> m >> k;
	while (m--) {
		cin >> u >> v >> a;
		u--;
		v--;
		it = distMap.find(a);
		if (it != distMap.end()) {
			it->second.insert(make_pair(u, v));
		} else {
			s.clear();
			s.insert(make_pair(u, v));
			distMap.insert(make_pair(a, s));
		}
	}

	for (i = 0; i < k; i++) {
		cin >> a;
		a--;
		cities[a] = 1;
	}

	cout << solve() << "\n";

	return 0;
}

/*
5 4 2
1 2 5
1 2 3
2 3 4
1 4 10
1 5
=====
3

3 1 1
1 2 3
3
=====
-1
*/
