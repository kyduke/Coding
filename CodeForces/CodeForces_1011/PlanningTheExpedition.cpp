// https://codeforces.com/contest/1011/problem/B

#include <iostream>
#include <set>

using namespace std;

int main() {
	multiset<int> s;
	multiset<int>::iterator it;
	int n, m, i, a, ans;
	int arr[101] = {0, };
	
	ans = 0;
	
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &a);
		arr[a]++;
	}
	
	for (i = 1; i <= 100; i++) {
		if (arr[i] > 0) {
			s.insert(arr[i]);
		}
	}
	
	for (i = 1; i <= 100; i++) {
		a = 0;
		for (it = s.begin(); it != s.end(); it++) {
			a += *it / i;
		}
		if (a >= n) {
			ans = i;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}

/*
4 10
1 5 2 1 1 1 2 5 7 2
=====
2

100 1
1
=====
0

2 5
5 4 3 2 1
=====
1

3 9
42 42 42 42 42 42 42 42 42
=====
3
*/
