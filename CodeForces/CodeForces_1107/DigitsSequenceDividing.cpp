// https://codeforces.com/contest/1107/problem/A

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef unsigned long long UINT64;
typedef long long INT64;

const int SIZE = 301;

char buffer[SIZE];

int main(int argc, char** argv) {
	int q, n;
	
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &n);
		scanf("%s", buffer);

		if (n == 2 && buffer[0] >= buffer[1]) {
			printf("NO\n");
		} else {
			printf("YES\n");
			printf("2\n");
			printf("%c %s\n", buffer[0], &buffer[1]);
		}
	}

	return 0;
}

/*
4
6
654321
4
1337
2
33
4
2122
=====
YES
2
6 54321
YES
2
1 337
NO
YES
2
2 122
*/
