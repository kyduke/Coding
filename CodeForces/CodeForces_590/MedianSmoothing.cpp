// http://codeforces.com/problemset/problem/590/A

#include <iostream>

using namespace std;

const int SIZE = 500000;

int arr[SIZE];
int n, updateCount;

void solve() {
	int i, start, end, maxLength, currLength;
	bool update;

	maxLength = 0;
	currLength = 0;
	for (i = 1; i < n; i++) {
		if (arr[i - 1] != arr[i]) {
			currLength++;
		} else {
			if (currLength > 1) {
				maxLength = max(maxLength, currLength);

				start = i - currLength;
				end = i - 2;
				while (start <= end) {
					arr[start++] = arr[i - currLength - 1];
					arr[end--] = arr[i - 1];
				}
			}
			currLength = 0;
		}
	}
	if (currLength > 1) {
		maxLength = max(maxLength, currLength);

		start = i - currLength;
		end = i - 2;
		while (start <= end) {
			arr[start++] = arr[i - currLength - 1];
			arr[end--] = arr[i - 1];
		}
	}

	updateCount = maxLength / 2;
}

int main(int argc, char* argv[]) {
	int i;

	cin >> n;
	i = 0;
	while (i < n) {
		cin >> arr[i];
		i++;
	}

	updateCount = 0;
	solve();

	cout << updateCount << "\n";
	for (i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	return 0;
}

/*
4
0 0 1 1
=====
0
0 0 1 1

5
0 1 0 1 0
=====
2
0 0 0 0 0
*/
