// http://codeforces.com/contest/935/problem/B

#include <iostream>

using namespace std;

const int SIZE = 100001;

char str[SIZE];

int main(int argc, char* argv[]) {
	int n, i, k, ans;
	
	scanf("%d", &n);
	scanf("%s", str);
	
	ans = 0;
	k = 0;
	n--;
	for (i = 0; i < n; i++) {
		if (str[i] == 'R') {
			k++;
		} else {
			k--;
		}
		if (k == 0 && str[i] == str[i + 1]) ans++;
	}
	
	printf("%d\n", ans);

	return 0;
}

/*
1
U
=====
0

6
RURUUR
=====
1

7
URRRUUU
=====
2
*/
