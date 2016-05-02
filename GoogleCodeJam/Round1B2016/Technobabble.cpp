// Google Code Jam Round 1B 2016 Problem C. Technobabble
// It is NOT a solution

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int solve(map<string, int>& x, map<string, int>& y, vector<pair<string, string>>& topics) {
	int result, i;

	result = 0;

	for (i = 0; i < topics.size(); i++) {
		if (x.find(topics[i].first)->second > 1
			&& y.find(topics[i].first) == y.end()
			&& y.find(topics[i].second)->second > 1
			&& x.find(topics[i].second) == x.end()) {
			result++;
		}
	}

	return result;
}

int main(int argc, char* argv[]) {
	int T, t, N;
	string a, b;
	map<string, int> x, y;
	map<string, int>::iterator it;
	vector<pair<string, string>> topics;

	cin >> T;
	t = 0;
	while (t < T) {
		topics.clear();
		cin >> N;
		while (N--) {
			cin >> a >> b;
			it = x.find(a);
			if (it == x.end()) {
				x.insert(make_pair(a, 1));
			} else {
				it->second++;
			}
			it = y.find(b);
			if (it == y.end()) {
				y.insert(make_pair(b, 1));
			} else {
				it->second++;
			}
			topics.push_back(make_pair(a, b));
		}
		t++;
		cout << "Case #" << t << ": " << solve(x, y, topics) << "\n";
	}

	return 0;
}

/*
3
3
HYDROCARBON COMBUSTION
QUAIL BEHAVIOR
QUAIL COMBUSTION
3
CODE JAM
SPACE JAM
PEARL JAM
2
INTERGALACTIC PLANETARY
PLANETARY INTERGALACTIC
=====
Case #1: 1
Case #2: 0
Case #3: 0
*/
