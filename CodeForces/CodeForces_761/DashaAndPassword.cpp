// CodeForces 761 C.Dasha and Password
// http://codeforces.com/contest/761/problem/C

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef unsigned long long UINT64;

const int LIMIT = 10000;
const int SIZE = 50;

vector<string> sa;
int arr[SIZE][3];

int getMin(int i, int n, bool a, bool b, bool c) {
	int ans, k;

	if (a == true && b == true && c == true) return 0;
	if (i >= n) return LIMIT;

	ans = LIMIT;
	if (a == false) {
		k = getMin(i + 1, n, true, b, c) + arr[i][0];
		ans = min(ans, k);
	}
	
	if (b == false) {
		k = getMin(i + 1, n, a, true, c) + arr[i][1];
		ans = min(ans, k);
	}
	
	if (c == false) {
		k = getMin(i + 1, n, a, b, true) + arr[i][2];
		ans = min(ans, k);
	}

	k = getMin(i + 1, n, a, b, c);
	ans = min(ans, k);

	return ans;
}

int solve(int n, int m) {
	int ans, i, j, k;

	ans = 0;

	for (i = 0; i < n; i++) {
		arr[i][0] = LIMIT;
		arr[i][1] = LIMIT;
		arr[i][2] = LIMIT;

		for (j = 0; j < m; j++) {
			if (sa[i][j] >= '0' && sa[i][j] <= '9') {
				arr[i][0] = min(arr[i][0], j);
				k = m - j;
				if (k > 0) {
					arr[i][0] = min(arr[i][0], k);
				}
			} else if (sa[i][j] >= 'a' && sa[i][j] <= 'z') {
				arr[i][1] = min(arr[i][1], j);
				k = m - j;
				if (k > 0) {
					arr[i][1] = min(arr[i][1], k);
				}
			} else if (sa[i][j] == '#' || sa[i][j] == '*' || sa[i][j] == '&') {
				arr[i][2] = min(arr[i][2], j);
				k = m - j;
				if (k > 0) {
					arr[i][2] = min(arr[i][2], k);
				}
			}
		}
	}

	ans = getMin(0, n, false, false, false);

	return ans;
}

int main(int argc, char* argv[]) {
	int n, m, i;
	string str;

	cin >> n >> m;

	for (i = 0; i < n; i++) {
		cin >> str;
		sa.push_back(str);
	}

	cout << solve(n, m) << "\n";

	return 0;
}

/*
3 4
1**2
a3*0
c4**
=====
1

5 5
#*&#*
*a1c&
&q2w*
#a3c#
*&#*&
=====
3
*/
