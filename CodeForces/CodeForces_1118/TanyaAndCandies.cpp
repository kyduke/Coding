// http://codeforces.com/contest/1118/problem/B

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 200001;

int arr[SIZE] = {0, };

int main() {
	UINT64 preOdd, preEven, postOdd, postEven;
	int ans, n, i;
	
	ans = 0;
	preOdd = 0;
	preEven = 0;
	postOdd = 0;
	postEven = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
		if (i % 2 == 0) {
			postEven += arr[i];
		} else {
			postOdd += arr[i];
		}
	}
	
	for (i = 0; i < n; i++) {
		if (i % 2 == 0) {
			postEven -= arr[i];
			if (preEven + postOdd == preOdd + postEven) {
				ans++;
			}
			preEven += arr[i];
		} else {
			postOdd -= arr[i];
			if (preEven + postOdd == preOdd + postEven) {
				ans++;
			}
			preOdd += arr[i];
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

/*
7
5 5 4 5 5 5 6
==========
2

8
4 8 8 7 8 4 4 5
==========
2

9
2 3 4 2 2 3 2 2 4
==========
3
*/
