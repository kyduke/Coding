// http://codeforces.com/contest/602/problem/B

#include <iostream>

using namespace std;

const int SIZE = 100000;

int arr[SIZE];
int diff[SIZE];
int n;

int main(int argc, char* argv[]) {
	int i, j, a, b, s, maxLength, minValue, maxValue, p1, p2;

	cin >> n;
	i = 0;
	minValue = 100001;
	maxValue = 0;
	while (i < 2) {
		cin >> arr[i];
		minValue = min(minValue, arr[i]);
		maxValue = max(maxValue, arr[i]);
		i++;
	}
	while (i < n) {
		cin >> arr[i];
		minValue = min(minValue, arr[i]);
		maxValue = max(maxValue, arr[i]);
		if (arr[i] != arr[i - 1] && arr[i] != arr[i - 2] && arr[i - 1] != arr[i - 2]) {
			diff[i - 2] = 1;
		}
		i++;
	}

	if (maxValue - minValue <= 1) {
		maxLength = n;
	} else {
		maxLength = 2;
		for (i = 0; i < n; i++) {
			if (diff[i] == 1) continue;
			a = -1;
			b = -1;
			s = i;
			for (j = i; j <= n; j++) {
				if (j == n) {
					if (j - s > maxLength) maxLength = j - s;
					break;
				}
				if (a == arr[j] || b == arr[j]) continue;
				if (a == -1) {
					a = arr[j];
				} else if (b == -1) {
					b = arr[j];
					i = j - 1;
				} else {
					if (j - s > maxLength) maxLength = j - s;
					break;
				}
			}
		}
	}

	cout << maxLength << "\n";

	return 0;
}

/*
5
1 2 3 3 2
=====
4

11
5 4 5 5 6 7 8 8 8 7 6
=====
5
*/
