// https://www.acmicpc.net/problem/9251

#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 1001;

int cache[SIZE][SIZE] = {0, };
char str[2][SIZE] = {0, };

int main() {
	int i, j, n, m;
	
	scanf("%s", str[0]);
	scanf("%s", str[1]);
	
	n = strlen(str[0]);
	m = strlen(str[1]);
	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (str[0][i - 1] == str[1][j - 1]) {
				cache[i][j] = cache[i - 1][j - 1] + 1;
			} else {
				cache[i][j] = max(cache[i][j - 1], cache[i - 1][j]);
			}
		}
	}
	
	printf("%d\n", cache[n][m]);
	
	return 0;
}


/*
ACAYKP
CAPCAK
=====
4
*/
