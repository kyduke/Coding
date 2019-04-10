// https://codeforces.com/contest/1041/problem/A

#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> s;
	set<int>::iterator it;
	int n, i, a, p;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		s.insert(a);
	}
	
	a = 0;
	it = s.begin();
	p = *it;
	it++;
	while (it != s.end()) {
		a += *it - p - 1;
		p = *it;
		it++;
	}
	
	printf("%d\n", a);
	
	return 0;
}

/*
4
10 13 12 8
=====
2

5
7 5 6 4 8
=====
0
*/
