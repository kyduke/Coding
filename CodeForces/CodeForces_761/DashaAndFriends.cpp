// CodeForces 761 B.Dasha and friends
// http://codeforces.com/contest/761/problem/B

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 50;

int doubleA[SIZE * 2];
int singleB[SIZE];

void solve(int n) {
	int i, j;
	bool flag;

	for (i = 0; i < n; i++) {
		flag = true;
		for (j = 0; j < n; j++) {
			if (singleB[j] != doubleA[i + j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

int main(int argc, char* argv[]) {
	int n, m, i, a, b, sum;

	cin >> n >> m;

	sum = 0;
	cin >> b;
	for (i = 1; i < n; i++) {
		cin >> a;
		doubleA[i - 1] = a - b;
		doubleA[i - 1 + n] = a - b;
		sum += a - b;
		b = a;
	}
	doubleA[i - 1] = m - sum;
	doubleA[i - 1 + n] = m - sum;

	sum = 0;
	cin >> b;
	for (i = 1; i < n; i++) {
		cin >> a;
		singleB[i - 1] = a - b;
		sum += a - b;
		b = a;
	}
	singleB[i - 1] = m - sum;

	solve(n);

	return 0;
}

/*
3 8
2 4 6
1 5 7
=====
YES

4 9
2 3 5 8
0 1 3 6
=====
YES

2 4
1 3
1 2
=====
NO
*/
