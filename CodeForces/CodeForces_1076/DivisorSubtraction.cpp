// https://codeforces.com/contest/1076/problem/B

#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long UINT64;

int main() {
	UINT64 ans, n, r, i, k;
	
	ans = 0;
	
	cin >> n;
	while (n % 2 == 1) {
		r = (UINT64)sqrt((double)n);
		k = n;
		for (i = 2; i <= r; i++) {
			if (n % i == 0) {
				k = i;
				break;
			}
		}
		ans++;
		n -= k;
	}
	ans += n / 2;
	
	cout << ans << "\n";
	
	return 0;
}

/*
5
=====
1

4
=====
2
*/
