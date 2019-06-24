// https://codeforces.com/contest/1079/problem/C

#include <iostream>

using namespace std;

const int SIZE = 100001;

int arr[SIZE] = {0, };
int ans[SIZE] = {0, };
int fix[SIZE] = {0, };
int dp[SIZE][6] = {0, };

bool solve(int n) {
	int i;
	
	for (i = 5; i < n; i++) {
		if (arr[i - 5] < arr[i - 4] && arr[i - 4] < arr[i - 3] && arr[i - 3] < arr[i - 2] && arr[i - 2] < arr[i - 1] && arr[i - 1] < arr[i]) return false;
		if (arr[i - 5] > arr[i - 4] && arr[i - 4] > arr[i - 3] && arr[i - 3] > arr[i - 2] && arr[i - 2] > arr[i - 1] && arr[i - 1] > arr[i]) return false;
	}
	
	for (i = 4; i < n; i++) {
		if (arr[i - 4] < arr[i - 3] && arr[i - 3] < arr[i - 2] && arr[i - 2] < arr[i - 1] && arr[i - 1] < arr[i]) {
			fix[i - 4] = 1;
			fix[i - 3] = 2;
			fix[i - 2] = 3;
			fix[i - 1] = 4;
			fix[i] = 5;
		}
		if (arr[i - 4] > arr[i - 3] && arr[i - 3] > arr[i - 2] && arr[i - 2] > arr[i - 1] && arr[i - 1] > arr[i]) {
			fix[i - 4] = 5;
			fix[i - 3] = 4;
			fix[i - 2] = 3;
			fix[i - 1] = 2;
			fix[i] = 1;
		}
	}
	
	for (i = 1; i < n - 1; i++) {
		if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
			fix[i] = 5;
		}
		if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1]) {
			fix[i] = 1;
		}
	}
	
	i = 0;
	ans[0] = fix[0];
	while (i < n) {
		if (fix[i] != 0) {
			if (i > 0) {
				if (arr[i - 1] == arr[i] && ans[i - 1] == ans[i]) {
					i--;
					continue;
				} else if (arr[i - 1] > arr[i] && ans[i - 1] <= ans[i]) {
					i--;
					continue;
				} else if (arr[i - 1] < arr[i] && ans[i - 1] >= ans[i]) {
					i--;
					continue;
				}
			}
			i++;
			ans[i] = 0;
			if (fix[i] != 0) ans[i] = fix[i];
			continue;
		}
		if (i == 0) {
			ans[i]++;
			if (ans[i] > 5) return false;
		} else {
			if (arr[i - 1] == arr[i]) {
				ans[i]++;
				if (ans[i - 1] == ans[i]) ans[i]++;
				if (ans[i] > 5) {
					ans[i] = 0;
					i--;
					if (fix[i] != 0) return false;
					continue;
				}
				if (dp[i][ ans[i] ] == 1) {
					continue;
				}
				dp[i][ ans[i] ] = 1;
			} else if (arr[i - 1] < arr[i]) {
				while (ans[i - 1] >= ans[i]) ans[i]++;
				if (ans[i] > 5) {
					ans[i] = 0;
					i--;
					if (fix[i] != 0) return false;
					continue;
				}
				if (dp[i][ ans[i] ] == 1) {
					ans[i]++;
					continue;
				}
				dp[i][ ans[i] ] = 1;
			} else {
				ans[i]++;
				if (ans[i - 1] <= ans[i]) {
					ans[i] = 0;
					i--;
					if (fix[i] != 0) return false;
					continue;
				}
				if (dp[i][ ans[i] ] == 1) {
					continue;
				}
				dp[i][ ans[i] ] = 1;
			}
		}
		i++;
		ans[i] = 0;
		if (fix[i] != 0) ans[i] = fix[i];
	}
	
	return true;
}

int main() {
	int n, i;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	if (solve(n) == true) {
		for (i = 0; i < n; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	} else {
		printf("-1\n");
	}
	
	return 0;
}

/*
5
1 1 4 2 2
=====
1 4 5 4 5 

7
1 5 7 8 10 3 1
=====
1 2 3 4 5 4 3 

19
3 3 7 9 8 8 8 8 7 7 7 7 5 3 3 3 3 8 8
=====
1 3 4 5 4 5 4 5 4 5 4 5 4 3 5 4 3 5 4 
*/
