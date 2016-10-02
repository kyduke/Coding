// http://codeforces.com/contest/722/problem/C

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 100002;

struct Node {
	UINT64 sum;
	int left;
	int right;
	bool used;
};

Node arr[SIZE];

void solve(int n, vector<int>& idxs) {
	vector<UINT64> ans;
	int i, k;
	UINT64 currentMax, temp;

	currentMax = 0;
	ans.push_back(0);

	arr[0].used = false;
	arr[n + 1].used = false;

	for (i = idxs.size() - 1; i > 1; i--) {
		k = idxs[i];
		if (arr[k - 1].used == true && arr[k + 1].used == true) {
			temp = arr[k - 1].sum + arr[k].sum + arr[k + 1].sum;
			arr[ arr[k - 1].left ].sum = temp;
			arr[ arr[k - 1].left ].right = arr[k + 1].right;
			arr[ arr[k + 1].right ].sum = temp;
			arr[ arr[k + 1].right ].left = arr[k - 1].left;
		} else if (arr[k - 1].used == true) {
			temp = arr[k - 1].sum + arr[k].sum;
			arr[ arr[k - 1].left ].sum = temp;
			arr[ arr[k - 1].left ].right = k;
			arr[k].sum = temp;
			arr[k].left = arr[k - 1].left;
		} else if (arr[k + 1].used == true) {
			temp = arr[k].sum + arr[k + 1].sum;
			arr[k].sum = temp;
			arr[k].right = arr[k + 1].right;
			arr[ arr[k + 1].right ].sum = temp;
			arr[ arr[k + 1].right ].left = k;
		} else {
			temp = arr[k].sum;
		}
		arr[k].used = true;

		currentMax = max(currentMax, temp);
		ans.push_back(currentMax);
	}

	for (i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << "\n";
	}
}

int main(int argc, char* argv[]) {
	vector<int> idxs;
	int n, i;

	cin >> n;
	idxs.assign(n + 1, 0);
	for (i = 1; i <= n; i++) {
		cin >> arr[i].sum;
		arr[i].left = i;
		arr[i].right = i;
		arr[i].used = false;
	}
	for (i = 1; i <= n; i++) {
		cin >> idxs[i];
	}

	solve(n, idxs);

	return 0;
}

/*
4
1 3 2 5
3 4 1 2
=====
5
4
3
0

5
1 2 3 4 5
4 2 3 5 1
=====
6
5
5
1
0

8
5 5 4 4 6 6 5 5
5 2 8 7 1 3 4 6
=====
18
16
11
8
8
6
6
0
*/
