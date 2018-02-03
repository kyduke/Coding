// https://www.hackerrank.com/contests/hourrank-26/challenges/cloudy-day

#include <iostream>
#include <map>

using namespace std;

typedef long long INT64;

struct Node {
	INT64 c;
	INT64 p;
	INT64 cloudId;
};

const int SIZE = 200000;

INT64 populations[SIZE] = {0, };
INT64 clouds[SIZE] = {0, };
INT64 sizes[SIZE] = {0, };
INT64 cloudPopulations[SIZE] = {0, };
map<INT64, Node> cities;

INT64 solve(INT64 n, INT64 m) {
	map<INT64, Node>::iterator it, jt;
	INT64 i, s, e, sum, maxOne;

	for (i = 0; i < m; i++) {
		s = clouds[i] - sizes[i];
		e = clouds[i] + sizes[i];
		it = cities.lower_bound(s);
		if (it == cities.end()) {
			it = cities.begin();
		}
		while (it != cities.end() && s <= it->first && it->first <= e) {
			it->second.c++;
			it->second.cloudId = i;
			if (it->second.c > 1) {
				jt = it;
				it++;
				cities.erase(jt);
			} else {
				it++;
			}
		}
	}

	sum = 0;
	for (it = cities.begin(); it != cities.end(); it++) {
		if (it->second.c == 0) {
			sum += it->second.p;
		} else if (it->second.c == 1) {
			cloudPopulations[it->second.cloudId] += it->second.p;
		}
	}

	maxOne = 0;
	for (i = 0; i < m; i++) {
		maxOne = max(maxOne, cloudPopulations[i]);
	}

	return sum + maxOne;
}

int main(int argc, char* argv[]) {
	map<INT64, Node>::iterator it;
	Node node;
	INT64 n, m, x, i;

	scanf("%lld", &n);
	for (i = 0; i < n; i++) {
		scanf("%lld", &populations[i]);
	}
	node.c = 0;
	for (i = 0; i < n; i++) {
		scanf("%lld", &x);
		it = cities.find(x);
		if (it == cities.end()) {
			node.p = populations[i];
			cities.insert(make_pair(x, node));
		} else {
			it->second.p += populations[i];
		}
	}

	scanf("%lld", &m);
	for (i = 0; i < m; i++) {
		scanf("%lld", &clouds[i]);
	}
	for (i = 0; i < m; i++) {
		scanf("%lld", &sizes[i]);
	}

	printf("%lld\n", solve(n, m));

	return 0;
}

/*
2
10 100
5 100
1
4
1
=====
110
*/
