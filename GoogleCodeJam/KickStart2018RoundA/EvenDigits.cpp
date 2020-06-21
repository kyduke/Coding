// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edf/00000000000510ed

#include <iostream>

using namespace std;

int main() {
	int t, ti, ans, n, k, a, b;
	
	scanf("%d", &t);
	for (ti = 1; ti <= t; ti++) {
		scanf("%d", &n);
		
		ans = 0;
		
		k = 1;
		while (k <= n) {
			k *= 10;
		}
		k /= 10;
		while (k > 0) {
			if ((n / k) % 2 == 1) {
				if ((n / k) % 10 == 9) {
					ans += (n % k) + 1 + (k - 1) / 9;
				} else {
					a = k - (n % k);
					b = (n % k) + 1 + (k - 1) / 9;
					ans += min(a, b);
				}
				break;
			}
			k /= 10;
		}
		
		printf("Case %d: %d\n", ti, ans);
	}
	
	return 0;
}

/*
4
42
11
1
2018
=====
Case #1: 0
Case #2: 3
Case #3: 1
Case #4: 2
*/
