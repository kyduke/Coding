// http://codeforces.com/contest/721/problem/A

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(string str, int n) {
	vector<int> arr;
	int i, k;

	k = 0;
	for (i = 0; i < n; i++) {
		if (str[i] == 'B') {
			k++;
		} else {
			if (k > 0) {
				arr.push_back(k);
			}
			k = 0;
		}
	}

	if (k > 0) {
		arr.push_back(k);
	}

	cout << arr.size() << "\n";
	for (i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
}

int main(int argc, char* argv[]) {
	int n;
	string str;

	cin >> n;
	cin >> str;

	solve(str, n);

	return 0;
}

/*
13
WBBBBWWBWBBBW
=====
3
4 1 3
*/
