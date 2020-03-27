// http://codeforces.com/contest/1100/problem/B

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	map<int, int> m;
	map<int, int>::iterator it, jt;
	int n, k, i, a;
	string ans = "";;
	
	scanf("%d %d", &n, &k);
	for (i = 0; i < k; i++) {
		scanf("%d", &a);
		m[a]++;
		if (m.size() == n) {
			ans += '1';
			it = m.begin();
			while (it != m.end()) {
				it->second--;
				if (it->second == 0) {
					jt = it;
					it++;
					m.erase(jt);
				} else {
					it++;
				}
			}
		} else {
			ans += '0';
		}
	}
	printf("%s\n", ans.c_str());
	
	return 0;
}

/*
3 11
2 3 1 2 2 2 3 2 2 3 1
=====
00100000001

4 8
4 1 3 3 2 3 3 3
=====
00001000
*/
