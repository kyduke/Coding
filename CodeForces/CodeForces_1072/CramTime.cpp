// https://codeforces.com/contest/1072/problem/C

#include <iostream>
#include <vector>

using namespace std;

typedef long long INT64;

int main() {
	int a, b, i;
	INT64 k, s;
	vector<int> as, bs;
	
	scanf("%d %d", &a, &b);
	s = ((INT64)a + (INT64)b) * (INT64)(2);
	
	k = 1;
	while (true) {
		if (k * (k + 1) > s) break;
		k++;
	}
	k--;
	
	while (k > 0) {
		if (a >= k) {
			as.push_back(k);
			a -= k;
		} else if (b >= k) {
			bs.push_back(k);
			b -= k;
		}
		k--;
	}
	
	printf("%d\n", as.size());
	for (i = 0; i < as.size(); i++) {
		printf("%d ", as[i]);
	}
	printf("\n");
	printf("%d\n", bs.size());
	for (i = 0; i < bs.size(); i++) {
		printf("%d ", bs[i]);
	}
	printf("\n");
	
	return 0;
}

/*
3 3
=====
1
3 
2
2 1 

9 12
=====
2
3 6
4
1 2 4 5
*/
