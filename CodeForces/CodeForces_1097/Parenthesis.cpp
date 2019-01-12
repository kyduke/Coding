// http://codeforces.com/contest/1097/problem/C

#include <iostream>
#include <map>
#include <cstring>

using namespace std;

const int SIZE = 500005;

map<int, int> leftOpen;
map<int, int> rightOpen;
int closes = 0;
char buffer[SIZE];

int calcLeftOpen() {
	int ans, i, l;
	
	ans = 0;
	l = strlen(buffer);
	for (i = l - 1; i >= 0; i--) {
		if (buffer[i] == ')') {
			ans++;
		} else {
			ans--;
		}
		if (ans < 0) return ans;
	}
	
	return ans;
}

int calcRightOpen() {
	int ans, i, l;
	
	ans = 0;
	l = strlen(buffer);
	for (i = 0; i < l; i++) {
		if (buffer[i] == '(') {
			ans++;
		} else {
			ans--;
		}
		if (ans < 0) return ans;
	}
	
	return ans;
}

int main(int argc, char** argv) {
	int ans, n, l, r;
	map<int, int>::iterator it, jt;
	
	scanf("%d", &n);
	while (n--) {
		scanf("%s", buffer);
		l = calcLeftOpen();
		r = calcRightOpen();
		if (l == 0 && r == 0) {
			closes++;
		} else if (l > 0 && r < 0) {
			leftOpen[l]++;
		} else if (l < 0 && r > 0) {
			rightOpen[r]++;
		}
	}
	
	ans = closes / 2;
	for (it = leftOpen.begin(); it != leftOpen.end(); it++) {
		jt = rightOpen.find(it->first);
		if (jt != rightOpen.end()) {
			ans += min(it->second, jt->second);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}

/*
7
)())
)
((
((
(
)
)
=====
2

4
(
((
(((
(())
=====
0

2
(())
()
=====
1
*/
