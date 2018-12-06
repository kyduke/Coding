// https://codeforces.com/contest/1013/problem/B

#include <iostream>
#include <map>

using namespace std;

map<int, int> original;
map<int, int> ANDed;

int main() {
	map<int, int>::iterator it;
	int n, x, i, a, b, ans;
	
	ans = -1;
	scanf("%d %d", &n, &x);
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		original[a]++;
		b = a & x;
		if (a != b) {
			ANDed[b]++;
		}
	}
	
	for (it = original.begin(); it != original.end(); it++) {
		if (it->second > 1) {
			ans = 0;
			break;
		}
	}
	
	if (ans == -1) {
		for (it = ANDed.begin(); it != ANDed.end(); it++) {
			if (original.find(it->first) != original.end()) {
				ans = 1;
				break;
			}
		}
	}
	
	if (ans == -1) {
		for (it = ANDed.begin(); it != ANDed.end(); it++) {
			if (it->second > 1) {
				ans = 2;
				break;
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}

/*
4 3
1 2 3 7
=====
1

2 228
1 1
=====
0

3 7
1 2 3
=====
-1
*/

