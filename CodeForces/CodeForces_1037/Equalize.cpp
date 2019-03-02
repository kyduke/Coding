// https://codeforces.com/contest/1037/problem/C

#include <iostream>

using namespace std;

const int SIZE = 1000001;

char strA[SIZE];
char strB[SIZE];

int main() {
	int n, i, ans;
	
	scanf("%d", &n);
	scanf("%s", strA);
	scanf("%s", strB);
	
	ans = 0;
	for (i = 0; i < n - 1; i++) {
		if (strA[i] != strB[i] && strA[i] != strA[i + 1] && strA[i + 1] != strB[i + 1]) {
			strA[i] = strB[i];
			strA[i + 1] = strB[i + 1];
			i++;
			ans++;
		}
	}
	for (i = 0; i < n; i++) {
		if (strA[i] != strB[i]) ans++;
	}
	printf("%d\n", ans);
	
	return 0;
}

/*
3
100
001
=====
2

4
0101
0011
=====
1
*/
