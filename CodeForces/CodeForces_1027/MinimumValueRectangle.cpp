// https://codeforces.com/contest/1027/problem/C

#include <iostream>
#include <map>

using namespace std;

map<int, int> m;

int main(int argc, char** argv) {
	int t, n, a, x, y;
	double ratio, temp, w, h;
	map<int, int>::iterator it, jt;
	
	scanf("%d", &t);
	while (t--) {
		m.clear();
		scanf("%d", &n);
		while (n--) {
			scanf("%d", &a);
			m[a]++;
		}
		
		ratio = 1000000000.0;
		for (it = m.begin(); it != m.end(); it++) {
			if (it->second < 2) continue;
			w = it->first;
			if (it->second >= 4) {
				temp = w * 4.0;
				temp = (temp * temp) / (w * w);
				if (ratio > temp) {
					ratio = temp;
					x = w;
					y = w;
				}
				continue;
			}
			jt = it;
			jt++;
			while (jt != m.end()) {
				if (jt->second < 2) {
					jt++;
					continue;
				}
				h = jt->first;
				temp = (w + h)* 2.0;
				temp = (temp * temp) / (w * h);
				if (ratio > temp) {
					ratio = temp;
					x = w;
					y = h;
				}
				break;
			}
		}
		
		printf("%d %d %d %d\n", x, x, y, y);
	}
	
	return 0;
}

/*
3
4
7 2 2 7
8
2 8 1 4 8 2 1 5
5
5 5 5 5 5
=====
2 7 7 2
2 2 1 1
5 5 5 5
*/
