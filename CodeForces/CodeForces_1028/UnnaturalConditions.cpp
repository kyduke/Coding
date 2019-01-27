// https://codeforces.com/contest/1028/problem/B

#include <iostream>

using namespace std;

const int SIZE = 116;

char buffer[SIZE];

int main() {
	int n, m, i;
	
	scanf("%d %d", &n, &m);
	
	for (i = 0; i < 230; i++) {
		printf("%d", 4 + (i % 2));
	}
	printf("5\n");
	for (i = 0; i < 230; i++) {
		printf("%d", 5 - (i % 2));
	}
	printf("5\n");
	
	return 0;
}

/*
6 5
=====
6 
7

8 16
=====
35 
53
*/
