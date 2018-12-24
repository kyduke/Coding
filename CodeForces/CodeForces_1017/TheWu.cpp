// https://codeforces.com/contest/1017/problem/D

#include <iostream>
#include <map>

using namespace std;

const int SIZE = 4096;

int table[SIZE][SIZE] = {0, };
int w[32];
char buffer[32];

map<int, int> ms;
int cnt[SIZE][101] = {0, };

int strToInt(int n) {
	int ans, i, k;
	
	ans = 0;
	k = 1;
	for (i = 0; i < n; i++) {
		if (buffer[i] == '1') {
			ans += k;
		}
		k *= 2;
	}
	
	return ans;
}

int calcW(int n, int x) {
	int ans, i;
	
	ans = 0;
	for (i = 0; i < n; i++) {
		if ((x & 1) ^ 1) {
			ans += w[i];
		}
		x /= 2;
	}
	
	return ans;
}

int main() {
	int n, m, q, i, j, k, a, ans;
	map<int, int>::iterator it;
	
	scanf("%d %d %d", &n, &m, &q);
	
	for (i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			table[i][j] = calcW(n, i ^ j);
		}
	}
	
	for (i = 0; i < m; i++) {
		scanf("%s", buffer);
		ms[ strToInt(n) ]++;
	}
	
	for (i = 0; i < SIZE; i++) {
		for (it = ms.begin(); it != ms.end(); it++) {
			if (table[i][ it->first ] <= 100) {
				cnt[i][ table[i][ it->first ] ] += it->second;
			}
		}
		for (j = 1; j <= 100; j++) {
			cnt[i][j] += cnt[i][j - 1];
		}
	}
	
	for (i = 0; i < q; i++) {
		scanf("%s", buffer);
		a = strToInt(n);
		scanf("%d", &k);
		
		ans = cnt[a][k];
		printf("%d\n", ans);
	}
	
	return 0;
}

/*
2 4 5
40 20
01
01
10
11
00 20
00 40
11 20
11 40
11 60
=====
2
4
2
3
4

1 2 4
100
0
1
0 0
0 100
1 0
1 100
=====
1
2
1
2
*/
