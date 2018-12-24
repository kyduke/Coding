// https://codeforces.com/contest/1017/problem/B

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 100001;

char strA[SIZE];
char strB[SIZE];

int main() {
	int n, i;
	UINT64 c0, c1, c00, c10;
	
	scanf("%d", &n);
	scanf("%s", strA);
	scanf("%s", strB);
	
	c0 = 0;
	c1 = 0;
	c00 = 0;
	c10 = 0;
	for (i = 0; i < n; i++) {
		if (strA[i] == '0') {
			c0++;
			if (strB[i] == '0') {
				c00++;
			}
		} else {
			c1++;
			if (strB[i] == '0') {
				c10++;
			}
		}
	}
	
	cout << c00 * c1 + c10 * c0 - c00 * c10 << "\n";
	
	return 0;
}

/*
5
01011
11001
=====
4

6
011000
010011
=====
6
*/
