// Google Code Jam Round 1C 2016 Problem A. Senate Evacuation

#include <iostream>

using namespace std;

void solve(int* arr, int n) {
	int i, j, k, remain;
	bool majority, single;
	char c;

	remain = 0;
	for (i = 0; i < n; i++) {
		remain += arr[i];
	}

	while (remain) {
		single = false;
		remain--;
		for (i = 0; i < n; i++) {
			if (arr[i] == 0) continue;
			arr[i]--;
			majority = false;
			for (j = 0; j < n; j++) {
				if (arr[j] + arr[j] > remain) {
					majority = true;
					break;
				}
			}
			if (majority == false) {
				single = true;
				break;
			}
			arr[i]++;
		}

		if (single) {
			c = 'A' + i;
			cout << c << " ";
			continue;
		}

		remain--;
		for (i = 0; i < n; i++) {
			if (arr[i] == 0) continue;
			arr[i]--;
			for (j = i; j < n; j++) {
				if (arr[j] == 0) continue;
				arr[j]--;
				majority = false;
				for (k = 0; k < n; k++) {
					if (arr[k] + arr[k] > remain) {
						majority = true;
						break;
					}
				}
				if (majority == false) break;
				arr[j]++;
			}
			if (majority == false) break;
			arr[i]++;
		}

		c = 'A' + i;
		cout << c;
		c = 'A' + j;
		cout << c << " ";
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	int arr[26];
	int T, t, n, i;

	cin >> T;
	t = 0;
	while (t < T) {
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> arr[i];
		}
		t++;
		cout << "Case #" << t << ": ";
		solve(arr, n);
	}

	return 0;
}

/*
4
2
2 2
3
3 2 2
3
1 1 2
3
2 3 1
=====
Case #1: AB BA
Case #2: AA BC C BA
Case #3: C C AB
Case #4: BA BB CA
*/
