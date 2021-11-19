// http://codeforces.com/contest/1139/problem/B

#include <iostream>
 
using namespace std;

typedef long long INT64;
 
const int SIZE = 200001;
INT64 arr[SIZE] = {0, };
 
int main() {
	INT64 ans, k;
	int n, i;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	k = arr[n - 1];
	ans = k;
	for (i = n - 2; i >= 0; i--) {
		if (arr[i] < k) {
			k = arr[i];
		} else {
			k--;
		}
		if (k <= 0) {
			break;
		}
		ans += k;
	}
	
	cout << ans << "\n";
	
	return 0;
}

/*
5
1 2 1 3 6
==========
10

5
3 2 5 4 10
==========
20

4
1 1 1 1
==========
1
*/
