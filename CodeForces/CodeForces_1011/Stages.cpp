// https://codeforces.com/contest/1011/problem/A

#include <iostream>

using namespace std;

int main() {
	int n, k, i, j, a, ans, temp;
	char str[51];
	int arr[27] = {0, };
	
	scanf("%d %d", &n, &k);
	scanf("%s", str);
	for (i = 0; i < n; i++) {
		arr[str[i] - 'a' + 1] = 1;
	}
	
	ans = 99999;
	for (i = 1; i <= 26; i++) {
		j = i;
		a = 0;
		temp = 0;
		while (a < k && j <= 26) {
			while (j <= 26 && arr[j] == 0) j++;
			if (j <= 26) {
				temp += j;
				a++;
				j += 2;
			}
		}
		
		if (a == k) {
			ans = min(ans, temp);
		}
	}
	
	if (ans == 99999) ans = -1;
	
	printf("%d\n", ans);
	
	return 0;
}

/*
5 3
xyabd
=====
29

7 4
problem
=====
34

2 2
ab
=====
-1

12 1
abaabbaaabbb
=====
1
*/
