// https://algospot.com/judge/problem/read/ZEROONE

#include <iostream>

using namespace std;

char str[1000001];
int group[1000000];

int main(int argc, char* argv[]) {
	int n, a, b;

	scanf("%s", str);
	a = str[0];
	b = 0;
	n = 0;
	while (str[n] != 0) {
		if (str[n] != a) {
			a = str[n];
			b++;
		}
		group[n] = b;
		n++;
	}

	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &a, &b);
		if (group[a] == group[b]) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}

	return 0;
}


/*
0000011111
3
0 5
4 2
5 9
=====
No
Yes
Yes
*/
