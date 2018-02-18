// http://codeforces.com/contest/939/problem/C

#include <iostream>

using namespace std;

typedef long long INT64;

const int SIZE = 100001;

int arr[SIZE];

int main(int argc, char* argv[]) {
	int n, i, j, a, b, c, ans;
	INT64 sum, temp;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d %d", &a, &b);

	c = b - a;
	ans = a;
	sum = 0;
	for (j = 0; j < c; j++) {
		sum += arr[j];
	}
	temp = sum;
	for (i = 1; i < n; i++) {
		j %= n;
		temp = temp - arr[i - 1] + arr[j];
		j++;
		if (temp > sum) {
			sum = temp;
			ans = n - i + a;
			if (ans > n) ans %= n;
		} else if (temp == sum) {
			c = n - i + a;
			if (c > n) c %= n;
			ans = min(ans, c);
		}
	}

	printf("%d\n", ans);

	return 0;
}

/*
3
1 2 3
1 3
=====
3

5
1 2 3 4 1
1 3
=====
4
*/
