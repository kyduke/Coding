// http://codeforces.com/contest/1020/problem/C

#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 3001;
const UINT64 MAX_COST = 10000000000000;

multiset<int> costs;
multiset<int> parties[SIZE];
map<int, vector<int>> countAndParties;

UINT64 solve(UINT64 cost, int votes, int targetVotes) {
	multiset<int>::iterator it;
	UINT64 ans;

	if (votes >= targetVotes) return cost;

	for (it = costs.begin(); it != costs.end(); it++) {
		cost += *it;
		votes++;
		if (votes == targetVotes) return cost;
	}

	return MAX_COST;
}

int main(int argc, char** argv) {
	int cnt, n, m, p, c, i, targetVotes;
	UINT64 ans, cost;
	vector<int> v;
	map<int, vector<int>>::iterator it, jt;
	multiset<int>::iterator kt;

	ans = MAX_COST;
	cnt = 0;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &p, &c);

		if (p == 1) {
			cnt++;
			continue;
		}
		costs.insert(c);
		parties[p].insert(c);
	}
	
	for (i = 2; i <= m; i++) {
		it = countAndParties.find(parties[i].size() * -1);
		if (it == countAndParties.end()) {
			v.clear();
			v.push_back(i);
			countAndParties.insert(make_pair(parties[i].size() * -1, v));
		} else {
			it->second.push_back(i);
		}
	}

	cost = 0;
	while (true) {
		if (countAndParties.size() > 0) {
			targetVotes = (countAndParties.begin()->first * -1) + 1;
		} else {
			targetVotes = 1;
		}
		ans = min(ans, solve(cost, cnt, targetVotes));
		if (cnt >= targetVotes) break;

		it = countAndParties.begin();
		i = it->first + 1;

		if (i == 0) {
			jt = countAndParties.end();
		} else {
			jt = countAndParties.find(i);
			if (jt == countAndParties.end()) {
				v.clear();
				countAndParties.insert(make_pair(i, v));
				jt = countAndParties.find(i);
			}
		}
		cnt += it->second.size();
		for (i = 0; i < it->second.size(); i++) {
			p = it->second[i];
			kt = parties[p].begin();
			cost += *kt;
			costs.erase(costs.find(*kt));
			parties[p].erase(kt);
			if (jt != countAndParties.end()) {
				jt->second.push_back(p);
			}
		}
		countAndParties.erase(it);
	}

	cout << ans << "\n";

	return 0;
}

/*
1 2
1 100
=====
0

5 5
2 100
3 200
4 300
5 400
5 900
=====
500

5 5
2 100
3 200
4 300
5 800
5 900
=====
600
*/
