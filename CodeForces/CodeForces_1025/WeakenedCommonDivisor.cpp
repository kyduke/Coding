// https://codeforces.com/contest/1025/problem/B

#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int SIZE = 150000;
int arr[SIZE][2];

int main(int argc, char** argv) {
	set<int> s, temp;
	set<int>::iterator it;
	set<pair<int, int>> used;
	int n, a, b, i;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
		s.insert(arr[i][0]);
		s.insert(arr[i][1]);
	}
	
	a = arr[0][0];
	b = arr[0][1];
	for (i = 2; i < 44722; i++) {
		if (a % i == 0) {
			s.insert(i);
			if ((a / i) > i) s.insert(a / i);
		}
		if (b % i == 0) {
			s.insert(i);
			if ((b / i) > i) s.insert(b / i);
		}
		if (i > a && i > b) break;
	}
	for (i = 0; i < n; i++) {
		a = arr[i][0];
		b = arr[i][1];
		if (used.find(make_pair(a, b)) != used.end()) continue;
		if (used.find(make_pair(b, a)) != used.end()) continue;
		used.insert(make_pair(a, b));
		used.insert(make_pair(b, a));
		for (it = s.begin(); it != s.end(); it++) {
			if (a % *it == 0) {
				temp.insert(*it);
				if (s.find(a / *it) != s.end()) temp.insert(a / *it);
			}
			if (b % *it == 0) {
				temp.insert(*it);
				if (s.find(b / *it) != s.end()) temp.insert(b / *it);
			}
			if (*it > a && *it > b) break;
		}
		s = temp;
		temp.clear();
	}
	
	if (s.size() > 0) {
		printf("%d\n", *s.begin());
	} else {
		printf("-1\n");
	}
	
	return 0;
}

/*
3
17 18
15 24
12 15
=====
6

2
10 16
7 17
=====
-1

5
90 108
45 105
75 40
165 175
=====
5
*/
