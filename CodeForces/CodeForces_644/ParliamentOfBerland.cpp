// http://codeforces.com/contest/644/problem/A

#include <iostream>
#include <vector>

using namespace std;

void solve(int n, int a, int b) {
	vector<int> arr;
	int i, j, k;

	k = 1;
	for (i = 0; i < a; i++) {
		arr.assign(b, 0);
		if (i % 2 == 0) {
			for (j = 0; j < b; j++) {
				if (k > n) {
					break;
				}
				arr[j] = k;
				k++;
			}
		} else {
			for (j = b - 1; j >= 0; j--) {
				if (k > n) {
					break;
				}
				arr[j] = k;
				k++;
			}
		}
		for (j = 0; j < b; j++) {
			cout << arr[j] << " ";
		}
		cout << "\n";
	}
}

int main(int argc, char argv[]) {
	int n, a, b;

	cin >> n >> a >> b;

	if (n > a * b) {
		cout << "-1\n";
	} else {
		solve(n, a, b);
	}

	return 0;
}

/*
3 2 2
=====
0 3
1 2

8 4 3
=====
7 8 3
0 1 4
6 0 5
0 2 0

10 2 2
=====
-1
*/
