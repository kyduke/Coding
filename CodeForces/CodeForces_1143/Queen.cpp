// http://codeforces.com/contest/1143/problem/C

#include <iostream>

using namespace std;

const int SIZE = 100001;
int ps[SIZE] = {0, };
int cs[SIZE] = {0, };
int hc[SIZE] = {0, };

int main() {
	int n, i, k;
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &ps[i], &cs[i]);
		if (ps[i] != -1) {
			hc[ ps[i] ] += 1 - cs[i];
		}
	}
	
	k = 0;
	for (i = 1; i <= n; i++) {
		if (cs[i] == 1 && hc[i] == 0) {
			k++;
		}
	}
	
	if (k == 0) {
		printf("-1\n");
	} else {
		for (i = 1; i <= n; i++) {
			if (cs[i] == 1 && hc[i] == 0) {
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	
	return 0;
}

/*
5
3 1
1 1
-1 0
2 1
3 0
==========
1 2 4 

5
-1 0
1 1
1 1
2 0
3 0
==========
-1

8
2 1
-1 0
1 0
1 1
1 1
4 0
5 1
7 0
==========
5 
*/
