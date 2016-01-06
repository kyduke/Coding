// https://www.hackerrank.com/challenges/cuttree

#include <iostream>
#include <vector>

typedef unsigned long long UINT64;

using namespace std;

const int SIZE = 51;
vector<int> link[SIZE];
UINT64 cache[SIZE][SIZE];
UINT64 temp[SIZE];
int n;

void solve(int curr, int parent) {
	int i, j, k, x;

	cache[curr][0] = 1;
	for (i = 0; i < link[curr].size(); i++) {
		x = link[curr][i];
		if (x == parent) continue;

		solve(x, curr);

		for (j = n - 1; j >= 0; j--) {
			temp[j + 1] = cache[curr][j];
		}
		temp[0] = 0;

		for (j = 0; j < n; j++) {
			for (k = 0; k < n - j; k++) {
				temp[j + k] += cache[curr][j] * cache[x][k];
			}
		}

		for (j = 0; j < n; j++) {
			cache[curr][j] = temp[j];
		}

		for (j = n - 1; j >= 0; j--) {
			cache[x][j + 1] = cache[x][j];
		}
		cache[x][0] = 0;
	}

}

int main(int argc, char* argv[]) {
	int k, i, j, x, y;
	UINT64 ans;

	cin >> n >> k;
	i = 0;
	while (i < n - 1) {
		cin >> x >> y;
		link[x].push_back(y);
		link[y].push_back(x);
		i++;
	}

	solve(1, 0);

	ans = 0;
	for (i = 1; i < n + 1; i++) {
		for (j = 0; j < k + 1; j++) {
			ans += cache[i][j];
		}
	}
	ans++;

	cout << ans << "\n";

	return 0;
}

/*
3 1
2 1
2 3
=====
6
*/
