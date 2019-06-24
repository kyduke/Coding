// https://codeforces.com/contest/1079/problem/B

#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 101;

char str[SIZE];

int main() {
	int n, k, c, r, i, j;
	bool flag;
	
	scanf("%s", str);
	n = strlen(str);
	
	k = n / 20;
	if (n % 20 != 0) k++;
	c = n / k;
	r = n % k;
	
	flag = r == 0;
	printf("%d %d\n", k, flag ? c : c + 1);
	
	i = 0;
	while (i < n) {
		for (j = 0; j < c; j++) {
			printf("%c", str[i]);
			i++;
		}
		if (flag) {
			printf("\n");
		} else if (r > 0) {
			printf("%c\n", str[i]);
			i++;
			r--;
		} else {
			printf("*\n");
		}
	}
	
	return 0;
}

/*
tourist
=====
1 7
tourist

MyNameIsLifeIAmForeverByYourSideMyNameIsLife
=====
3 15
MyNameIsLifeIAm
ForeverByYourSi
deMyNameIsL*ife
*/
