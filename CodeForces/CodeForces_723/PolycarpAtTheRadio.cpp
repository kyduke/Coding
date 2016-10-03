// http://codeforces.com/contest/723/problem/C

#include <iostream>

using namespace std;

const int SIZE = 2001;

int arr[SIZE] = {0, };
int count[SIZE] = {0, };
int diff[SIZE] = {0, };
int answers[SIZE] = {0, };

void solve(int n, int m, int other) {
	int quota, remain, inner, ans, i, k;

	quota = n / m;
	remain = n % m;
	inner = 0;
	ans = 0;

	for (i = 1; i <= m; i++) {
		while (true) {
			if (diff[i] == quota) break;
			if (diff[i] < quota) {
				if (inner > 0) {
					inner--;
				} else if (other > 0) {
					other--;
					ans++;
				} else {
					inner--;
					ans++;
				}
				diff[i]++;
			} else if (diff[i] == quota + 1) {
				if (remain > 0) {
					remain--;
					break;
				}
				if (inner < 0) {
					inner++;
				} else {
					inner++;
					ans++;
				}
				diff[i]--;
				arr[i] = 0;
			} else {
				if (inner < 0) {
					inner++;
				} else {
					inner++;
					ans++;
				}
				diff[i]--;
				arr[i] = 0;
			}
		}
	}

	for (i = 1; i <= m; i++) {
		if (remain == 0) break;
		if (diff[i] == quota) {
			remain--;
			diff[i]++;
		}
	}

	k = 0;
	for (i = 1; i <= m; i++) {
		if (diff[i] > count[i]) {
			diff[i] -= count[i];
			while (diff[i]--) {
				answers[k] = i;
				k++;
			}
		} else {
			diff[i] = 0;
		}
	}

	k = 0;
	for (i = 0; i < n; i++) {
		if (k == ans) break;
		if (arr[i] == 0) {
			arr[i] = answers[k];
			k++;
		}
	}

	cout << quota << " " << ans << "\n";
	for (i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main(int argc, char* argv[]) {
	int n, m, other, a, i;

	other = 0;

	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> a;
		if (a <= m) {
			arr[i] = a;
			count[a]++;
			diff[a]++;
		} else {
			other++;
		}
	}

	solve(n, m, other);

	return 0;
}

/*
4 2
1 2 3 2
=====
2 1
1 2 1 2 

7 3
1 3 2 2 2 2 1
=====
2 1
1 3 3 2 2 2 1 

4 4
1000000000 100 7 1000000000
======
1 4
1 2 3 4 
*/
