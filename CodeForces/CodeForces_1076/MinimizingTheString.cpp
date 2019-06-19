// https://codeforces.com/contest/1076/problem/A

#include <iostream>

using namespace std;

const int SIZE = 200001;

char str[SIZE];

int main() {
	int n, i, k;
	
	scanf("%d", &n);
	scanf("%s", str);
	
	k = n - 1;
	for (i = 0; i < n - 1; i++) {
		if (str[i] > str[i + 1]) {
			k = i;
			break;
		}
	}
	
	for (i = 0;i < n; i++) {
		if (i == k) continue;
		printf("%c", str[i]);
	}
	printf("\n");
	
	return 0;
}

/*
3
aaa
=====
aa

5
abcda
=====
abca
*/
