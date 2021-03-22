// http://codeforces.com/contest/1138/problem/B
// 두 그룹으로 나누어서 비교해야 하는 숫자의 최소와 최대르 구함
// 최소는 둘을 모두 포함하는 원소들의 개수의 반
// 최대는 하나만 포함하는 원소들 그룹 둘 중에서 작은 것과 둘 모두 포함하는 개수의 합
// 최소부터 최대까지 순회하면서 주어진 수를 만들수 있는 경우를 만들 수 있는지 확인

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 5001;

char buffer[2][SIZE] = { 0, };
vector<int> a, b, c, d, ans;

bool solve(int k, int n) {
	int i, j, r, s, t, u;

	for (i = 0; i <= min(k, (int)d.size()); i++) {
		j = k - i;
		if (b.size() < j) {
			continue;
		}

		r = d.size() - i;
		if (r > k) {
			continue;
		}
		s = k - r;
		if (c.size() < s) {
			continue;
		}
		t = k + c.size() - s;
		u = k + b.size() - j;
		if (t > n / 2 || u > n / 2) {
			continue;
		}

		for (u = 0; u < i; u++) {
			ans.push_back(d[u]);
		}
		for (u = 0; u < j; u++) {
			ans.push_back(b[u]);
		}
		for (u = 0; u < c.size() - s; u++) {
			ans.push_back(c[u]);
		}
		for (u = 0; u < (n / 2) - t; u++) {
			ans.push_back(a[u]);
		}

		return true;
	}

	return false;
}

int main(int argc, char** argv) {
	int n, i, minV, maxV;

	cin >> n;
	cin >> buffer[0];
	cin >> buffer[1];

	for (i = 0; i < n; i++) {
		if (buffer[0][i] == '0' && buffer[1][i] == '0') {
			a.push_back(i + 1);
		} else if (buffer[0][i] == '1' && buffer[1][i] == '0') {
			b.push_back(i + 1);
		} else if (buffer[0][i] == '0' && buffer[1][i] == '1') {
			c.push_back(i + 1);
		} else if (buffer[0][i] == '1' && buffer[1][i] == '1') {
			d.push_back(i + 1);
		}
	}

	minV = d.size() / 2;
	maxV = min(b.size(), c.size()) + d.size();
	for (i = 0; i <= maxV; i++) {
		if (solve(i, n) == true) {
			for (i = 0; i < n / 2; i++) {
				cout << ans[i] << " ";
			}
			cout << "\n";

			return 0;
		}
	}

	cout << "-1\n";

	return 0;
}

/*
4
0011
0101
=====
1 4

6
000000
111111
=====
-1

4
0011
1100
=====
4 3

8
00100101
01111100
=====
1 2 3 6
*/
