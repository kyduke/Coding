// https://codeforces.com/contest/1037/problem/A

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	
	scanf("%d", &n);
	printf("%d", (int)log2((double)n) + 1);
	
	return 0;
}

/*
6
=====
3

2
=====
2
*/
