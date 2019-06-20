// https://codeforces.com/contest/1062/problem/C

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 100001;
const UINT64 DIV = 1000000007;

UINT64 arr[SIZE];
UINT64 nxt[SIZE];
char str[SIZE];
int numberOfOnes[SIZE];

void init() {
	UINT64 i;
	
	arr[0] = 0;
	nxt[0] = 1;
	for (i = 1; i < SIZE; i++) {
		arr[i] = (arr[i - 1] + nxt[i - 1]) % DIV;
		nxt[i] = (nxt[i - 1] * 2) % DIV;
	}
}

int main() {
	int n, q, l, r, a, b, i;
	UINT64 ans;
	
	init();
	
	scanf("%d %d", &n, &q);
	scanf("%s", str);
	
	numberOfOnes[0] = 0;
	for (i = 0; i < n; i++) {
		numberOfOnes[i + 1] = numberOfOnes[i];
		if (str[i] == '1') {
			numberOfOnes[i + 1]++;
		}
	}
	
	while (q--) {
		scanf("%d %d", &l, &r);
		a = numberOfOnes[r] - numberOfOnes[l - 1];
		b = (r - l + 1) - a;
		ans = (arr[a] + ((arr[b] * (nxt[a] - 1)) % DIV)) % DIV;
		cout << ans << "\n";
	}
	
	return 0;
}

/*
4 2
1011
1 4
3 4
=====
14
3

3 2
111
1 2
3 3
=====
3
1
*/
