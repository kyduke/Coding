// https://codeforces.com/contest/1075/problem/C

#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 100001;

int v[SIZE];
int h[SIZE];

int main() {
	int n, m, i, j, k, a, b, c, ans;
	
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	v[i] = 1000000000;
	sort(v, v + n + 1);
	
	k = 0;
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			h[k] = b;
			k++;
		}
	}
	sort(h, h + k);
	
	ans = 2000000000;
	
	j = 0;
	for (i = 0; i <= n; i++) {
		while (j < k) {
			if (h[j] >= v[i]) break;
			j++;
		}
		ans = min(ans, k - j + i);
	}
	
	cout << ans << "\n";
	
	return 0;
}

/*
2 3
6
8
1 5 6
1 9 4
2 4 2
=====
1

1 3
4
1 5 3
1 9 4
4 6 6
=====
1

0 2
1 1000000000 4
1 1000000000 2
=====
2

0 0
=====
0

2 3
4
6
1 4 3
1 5 2
1 6 5
=====
2
*/
