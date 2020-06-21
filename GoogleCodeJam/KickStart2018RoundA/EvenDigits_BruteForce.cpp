// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edf/00000000000510ed

#include <iostream>
#include <queue>
#include <set>

using namespace std;

bool isEven(int n) {
	while (n) {
		if (n % 2 == 1) return false;
		n /= 10;
	}
	return true;
}

int main() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>> > q;
	set<int> s;
	int t, ti, ans, n, k;
	
	scanf("%d", &t);
	for (ti = 1; ti <= t; ti++) {
		scanf("%d", &n);
		
		ans = n;
		s.clear();
		s.insert(n);
		q.push(make_pair(0, n));
		while (!q.empty()) {
			k = q.top().first;
			n = q.top().second;
			q.pop();
			if (k >= ans) continue;
			if (isEven(n) == true) {
				ans = min(ans, k);
			} else {
				if (s.find(n + 1) == s.end()) {
					s.insert(n + 1);
					q.push(make_pair(k + 1, n + 1));
				}
				if (s.find(n - 1) == s.end()) {
					s.insert(n - 1);
					q.push(make_pair(k + 1, n - 1));
				}
			}
		}
		
		printf("Case %d: %d\n", ti, ans);
	}
	
	return 0;
}

/*
4
42
11
1
2018
=====
Case #1: 0
Case #2: 3
Case #3: 1
Case #4: 2
*/
