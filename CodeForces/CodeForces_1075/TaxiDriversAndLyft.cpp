// https://codeforces.com/contest/1075/problem/B

#include <iostream>
#include <map>
#include <set>

using namespace std;

const int SIZE = 200000;

int arr[SIZE];

int main() {
	set<int> r;
	set<int>::iterator it;
	map<int, int> t;
	map<int, int>::iterator tl, tr;
	int n, m, i, k;
	
	scanf("%d %d", &n, &m);
	for (i = 0; i < n + m; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n + m; i++) {
		scanf("%d", &k);
		if (k == 1) {
			t.insert(make_pair(arr[i], 0));
		} else {
			r.insert(arr[i]);
		}
	}
	
	for (it = r.begin(); it != r.end(); it++) {
		tl = t.upper_bound(*it);
		while (true) {
			if (tl != t.end() && tl->first < *it) break;
			if (tl == t.begin() && tl->first > *it) {
				tl = t.end();
				break;
			}
			tl--;
		}
		tr = t.upper_bound(*it);
		if (tl == t.end()) {
			tr->second++;
		} else if (tr == t.end()) {
			tl->second++;
		} else {
			if ((*it - tl->first) <= (tr->first - *it)) {
				tl->second++;
			} else {
				tr->second++;
			}
		}
	}
	
	for (tl = t.begin(); tl != t.end(); tl++) {
		printf("%d ", tl->second);
	}
	printf("\n");
	
	return 0;
}

/*
3 1
1 2 3 10
0 0 1 0
=====
3 

3 2
2 3 4 5 6
1 0 0 0 1
=====
2 1 

1 4
2 4 6 10 15
1 1 1 1 0
=====
0 0 0 1
*/
