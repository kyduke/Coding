// https://codeforces.com/contest/1025/problem/A

#include <iostream>

using namespace std;

const int SIZE = 100001;

char str[SIZE];

int main(int argc, char** argv) {
	int n, i;
	bool ans;
	int alpha[26] = {0, };
	
	scanf("%d", &n);
	scanf("%s", str);
	
	ans = false;
	for (i = 0; i < n; i++) {
		if (alpha[ str[i] - 'a' ] == 1) {
			ans = true;
			break;
		}
		alpha[ str[i] - 'a' ]++;
	}
	
	if (n == 1 || ans == true) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
}

/*
6
aabddc
=====
Yes

3
abc
=====
No

3
jjj
=====
Yes
*/
