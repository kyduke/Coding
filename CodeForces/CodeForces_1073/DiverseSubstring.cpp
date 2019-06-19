// https://codeforces.com/contest/1073/problem/A

#include <iostream>

using namespace std;

const int SIZE = 1001;

char buffer[SIZE] = {0, };
int cnt[26] = {0, };

int main() {
	int n, i, k;
	bool flag;
	
	scanf("%d", &n);
	scanf("%s", buffer);
	for (i = 0; i < n; i++) {
		k = buffer[i] - 'a';
		cnt[k]++;
	}
	
	flag = false;
	for (i = 0; i < n; i++) {
		k = buffer[i] - 'a';
		if (cnt[k] <= n / 2) {
			flag = true;
			break;
		}
	}
	
	if (flag == true) {
		printf("YES\n");
		for (i = 0; i < n - 1; i++) {
			if (buffer[i] != buffer[i + 1]) {
				printf("%c%c\n", buffer[i], buffer[i + 1]);
				break;
			}
		}
	} else {
		printf("NO\n");
	}
	
	
	return 0;
}

/*
10
codeforces
=====
YES
code

5
aaaaa
=====
NO
*/
